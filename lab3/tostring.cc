#include <sstream>
#include <iostream>
#include <stdexcept>
#include "date.h"

using namespace std;

template<class T>
string toString(T& input){
	ostringstream oss;
	oss << input;
	return oss.str();
}

template<class T>
T string_cast(const string& s){
	T result;
	istringstream iss(s);
	iss >> result;
	if(iss.fail()){
		throw invalid_argument("Oops!");
	}
	return result;
}

int main(){
	double d = 1.234;
	Date today;
	string sd = toString(d);
	string st = toString(today);

	int i = 0;
	double d2;
	Date date;

	try {
		i = string_cast<int>("123");
		d2 = string_cast<double>("12.34");
		date = string_cast<Date>("2013-01-10");
	} catch (invalid_argument& e){
		cout << "Error: " << e.what() << endl;
	}	
	

	cout << sd << ", " << st << ", " << i << ", " << d2 << ", " << date << endl;
}
