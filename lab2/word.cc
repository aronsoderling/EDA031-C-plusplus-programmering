#include <string>
#include <vector>
#include "word.h"

using namespace std;

Word::Word(const string& w, const vector<string>& t) : word(w), trigrams(t) {}

string Word::get_word() const {
	return word;
}

unsigned int Word::get_matches(const vector<string>& t) const {
	int result = 0;
	size_t s1 = trigrams.size();
	size_t s2 = t.size();
	for(size_t i=0; i<s1; i++){
		for(size_t j=0; j<s2; j++){
			if(trigrams[i] == t[j]){
				result++;
			}
		}
	}
	return result;
}


