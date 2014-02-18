#ifndef TAG_REMOVER_HEADER
#define TAG_REMOVER_HEADER

#include <iostream>
#include <string>

class TagRemover{
public:
	TagRemover(std::istream& is);
	void print(std::ostream& os);
private:
	std::string str;
};
#endif
