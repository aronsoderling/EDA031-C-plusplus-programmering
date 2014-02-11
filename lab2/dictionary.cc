#include <string>
#include <vector>
#include <unordered_set>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "word.h"
#include "dictionary.h"

using namespace std;

Dictionary::Dictionary() {
	ifstream is;
	is.open("./words.txt");
	do{
		string line;
		getline(is, line);
		vector<string> split = split(line, ' ');
		string word = split[0];
		int size = split[1];
		
		vector<string> trigrams; //(split.begin()+2, split.end());
		set.insert(Word(word, trigrams));
		//cout << word << endl;
	}while(is.good());
}

bool Dictionary::contains(const string& word) const {
	auto found = set.find(word);
	return found != set.end();
}

vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
	return suggestions;
}
