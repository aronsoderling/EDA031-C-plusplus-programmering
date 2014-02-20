#include <ctime>  // time and localtimei
#include <sstream>
#include <iostream>
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

Date::Date(int y, int m, int d) : year(y), month(m), day(d) {}

int Date::getYear() const {
	return year;
}

int Date::getMonth() const {
	return month;
}

int Date::getDay() const {
	return day;
}

void Date::next() {
	++day;
	if(day > daysPerMonth[ month - 1 ]){
		day = 1;
		++month;
	}
	if(month > 12){
		month = 1;
		++year;
	}
}

istream& operator>>(istream& is, Date& d) {
	string str;
	is >> str;
	
	istringstream iss(str);

	string token;

	getline(iss, token, '-');
	int dyear = stoi(token);
	
	getline(iss, token, '-');
	int dmonth = stoi(token);

	getline(iss, token, '-');
	int dday = stoi(token);

	if(dmonth < 1 || dmonth > 12 || dday < 1 || dday > Date::daysPerMonth[ dmonth ]){
		cerr << "Invalid format" << endl;
	}else{
		d.year = dyear;
		d.month = dmonth;
		d.day = dday;
	}

	return is;
}
ostream& operator<<(ostream& os, const Date& d){
	string superday = (d.day < 10) ? "0"+to_string(d.day) : to_string(d.day);
	string supermonth = (d.month < 10) ? "0"+to_string(d.month) : to_string(d.month);
	os << d.year << "-" << supermonth << "-" << superday;
	return os;
}
