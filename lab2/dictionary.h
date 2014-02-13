#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <vector>
#include <unordered_set>
#include "word.h"



class Dictionary {
public:
	Dictionary();
	bool contains(const std::string& word) const;
	std::vector<std::string> get_suggestions(const std::string& word);
	void add_trigram_suggestions(const std::string& str, std::vector<Word>& suggestions);
	std::vector<std::string> rank_suggestions(const std::string& str, std::vector<Word>& suggestions);
	void trim_suggestions(std::vector<std::string>& suggestions);
	int comp_distance(const std::string& s1, const std::string& s2);
private:
	std::unordered_set<Word, Hash, Eq> set;
	std::vector< std::vector<Word> > words;
};


#endif
