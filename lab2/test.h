#ifndef TEST_H
#define TEST_H

#include <string>
#include <unordered_set>

class Test {
public:
	Test(const std::string& t);
	
	std::string get_s() const;
	
private:
	std::string s;
};

struct Hash {
	size_t operator()(const Test& p) const {
		return std::hash<std::string>()(p.get_s());
	}
};
struct Eq {
	bool operator()(const Test& p1, const Test& p2) const {
		return p1.get_s() == p2.get_s();
	}
};

#endif
