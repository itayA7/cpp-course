#include "Date.h"
#include <iostream>
#include <fstream>
using namespace std;

Date::Date(int d, int m, int y) {
	if (d < 1 || d>31) throw "invalid date";
	if (m < 1 || m>12) throw "invalid date";
	day = d;
	month = m;
	year = y;
}
void Date::setDate(int d, int m, int y) {
	if (d < 1 || d>31) throw "invalid date";
	if (m < 1 || m>12) throw "invalid date";
	day = d;
	month = m;
	year = y;
}

std::ostream& operator<<(std::ostream& out, const Date& d) {
	out << d.day << "/" << d.month << "/" << d.year << endl;
	return out;
}

const Date& Date::operator=(const Date& d) {
	day = d.day;
	month = d.month;
	year = d.year;
	return *this;
}

bool Date::operator==(const Date& d)const {
	if (day != d.day) { return false; }
	if (month != d.month) { return false; }
	if (year != d.year) { return false; }
	return true;
}

Date::Date() {
	day = 1;
	month = 1;
	year = 2024;
	cout << "In Date()" << endl;
}

bool Date::operator<(const Date& d) const {
	if (year < d.year) return true;
	if (month < d.month)return true;
	if (day < d.day)return true;
	return false;
}