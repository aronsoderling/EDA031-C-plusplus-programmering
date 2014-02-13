#include <string>
#include <sstream>
#include <vector>
#include <unordered_set>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "dictionary.h"

using namespace std;

Dictionary::Dictionary() {
	for(int i=0; i<25; i++){
		words.push_back(vector<Word>());
	}
	ifstream is;
	is.open("./words.txt");
	do{
		string line;
		string word;
		int size;
		getline(is, line);
	
		istringstream iss(line);

		iss >> word;
		iss >> size;
		
		vector<string> trigrams; //(split.begin()+2, split.end());

		//cout << "Word: " << word << endl;
		
		for(int i=0; i<size; i++){
			string sub;
			iss >> sub;
			trigrams.push_back(sub);
			//cout << "Substring: " << sub << endl;
		}

		Word coolWord(word, trigrams);
	
		set.insert(coolWord);
		words[word.size()].push_back(coolWord);
		//cout << word << endl;
	}while(is.good());

	/*for (const auto& elem: set) {
		cout << elem.get_word() << endl;
	}*/
}

bool Dictionary::contains(const string& word) const {
	vector<string> temp;
	return set.count(Word(word, temp)) == 1;
}

vector<string> Dictionary::get_suggestions(const string& word) {
	vector<Word> s1;
	add_trigram_suggestions(word, s1);
	vector<string> suggestions;
	for(Word w : s1){
		suggestions.push_back( w.get_word() );
	}

	vector<string> ranked = rank_suggestions(word, s1);

	trim_suggestions(ranked);

	return ranked;
}

void Dictionary::add_trigram_suggestions(const string& str, vector<Word>& suggestions){
	vector<string> trigrams;
	if(str.size() >= 3){
		for(size_t i=0; i<=str.size()-3; i++){
			trigrams.push_back(str.substr(i,3));
		}
		
		sort(trigrams.begin(), trigrams.end());
	}

	for(Word w : set){
		if(w.get_matches(trigrams) > 0){
			suggestions.push_back(w);
		}
	}
}

vector<string> Dictionary::rank_suggestions(const string& str, vector<Word>& suggestions){
	vector<pair<int, string>> rank;
	for(Word w : suggestions){
		int dist = comp_distance(str, w.get_word());
		rank.push_back(make_pair(dist, w.get_word()));
	}
	sort(rank.begin(), rank.end());
	int size = rank.size();
	vector<string> result;
	for(int i=0; i<size; i++){
		result.push_back(rank[i].second);
	}
	return result;
}

void Dictionary::trim_suggestions(vector<string>& suggestions){
	suggestions.resize(5);
}

int Dictionary::comp_distance(const string& s1, const string& s2){
	int d[26][26];
	int size1 = s1.size(); 
	int size2 = s2.size();
	
	d[0][0] = 0;

	for(int i=1; i<=size1; i++){
		d[i][0] = i;
	}
	for(int j=1; j<=size2; j++){
		d[0][j] = j;
	}
	for(int i=1; i<=size1; i++){
		for(int j=1; j<=size2; j++){
			int m1;
			if(s1.at(i-1) == s2.at(j-1)){
				m1 = d[i-1][j-1];
			}else{
				m1 = d[i-1][j-1] + 1;
			}
			m1 = min(m1, d[i-1][j] + 1);
			m1 = min(m1, d[i][j-1] + 1);
			
			d[i][j] = m1;
		}
	}
	return d[size1][size2];
}
