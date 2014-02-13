#include <string>
#include <vector>
#include "test.h"

using namespace std;

Test::Test(const string& t) : s(t){}

string Test::get_s() const {
	return s;
}

int main(){
	Test t("hej");
	Test t2("hopp");
	
	unordered_set<Test, Hash, Eq> myset;

	myset.insert(t);
	myset.insert(t2);
}
