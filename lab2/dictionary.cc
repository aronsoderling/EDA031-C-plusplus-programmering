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
	return suggestions;
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
