#include <ctime>  // time and localtimei
#include <sstream>
#include "date.h"

using namespace std;

int Date::daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date() {
	time_t timer = time(0); // time in seconds since 1970-01-01
	tm* locTime = localtime(&timer); // broken-down time
	year = 1900 + locTime->tm_year;
	month = 1 + locTime->tm_mon;
	day = locTime->tm_mday;
}

Date::Date(int y, int m, int d) {}

int Date::getYear() const {
	return 0;
}

int Date::getMonth() const {
	return 0;
}

int Date::getDay() const {
	return 0;
}

void Date::next() {
}

istream& operator>>(istream& is, Date& d) {
	string str;
	is >> str;
	
	istringstream iss(str);

	string token;

	getline(ss, token, '-';
	token >> d.year;
	
	getline(ss, token, '-';
	token >> d.month;

	getline(ss, token, '-';
	token >> d.day;

	return is;
}
std::ostream& operator<<(std::ostream& os, const Date& d){
	os << d.year << "-" << d.month << "-" << d.day;
	return os;
}
