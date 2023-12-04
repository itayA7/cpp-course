#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date(int day, int month, int year);
    Date();
    Date operator=(const Date &other);
    bool operator==(const Date &other);
    bool operator>(const Date &other);
    bool operator<(const Date &other);
    friend ostream &operator<<(ostream &os, const Date &dt);

    int getDay();
    int getMonth();
    int getYear();
    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);
};

#endif