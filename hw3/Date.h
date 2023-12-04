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
    Date(int day, int month, int year)
    {
        setDay(day);
        setMonth(month);
        setYear(year);
    }
    Date()
    {
        Date(1, 1, 2004);
    }
    Date &operator=(const Date &other)
    {
        if (this == &other)
        {
            return *this;
        }
        this->day = other.day;
        this->month = other.month;
        this->year = other.year;
        return *this;
    }

    int getDay()
    {
        return this->day;
    }
    int getMonth()
    {
        return this->month;
    }
    int getYear()
    {
        return this->year;
    }
    void setDay(int day)
    {
        if (day < 1 || day > 30)
        {
            day = 0;
        }
        this->day = day;
    }
    void setMonth(int month)
    {
        if (month < 1 || month > 12)
        {
            month = 0;
        }
        this->month = month;
    }
    void setYear(int year)
    {
        this->year = year;
    }

    void PrintDate()
    {
        cout << day << '/' << month << '/' << year;
    }
};

#endif