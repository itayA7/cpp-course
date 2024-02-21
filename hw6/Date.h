#pragma once
#include <iostream>
#include <fstream>
class Date
{
protected:
	int day;
	int month;
	int year;
public:

	int GetDay() const { return day; }
	int GetMonth() const { return month; }
	int GetYear() const { return year; }


	Date(int d, int m, int y = 2024);
	void setDate(int d, int m, int y = 2024);

	Date();


	friend std::ostream& operator<<(std::ostream& out, const Date& d);

	bool operator==(const Date& d) const;
	bool operator<(const Date& d) const;

	const Date& operator=(const Date& d);
};