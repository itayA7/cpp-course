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

Date::Date(int day, int month, int year)
{
    setDay(day);
    setMonth(month);
    setYear(year);
}

Date::Date()
{
    Date(1, 1, 2004);
}

Date Date::operator=(const Date &other)
{
    if (*this == other)
    {
        return *this;
    }
    this->day = other.day;
    this->month = other.month;
    this->year = other.year;
    return *this;
}

bool Date::operator==(const Date &other)
{
    bool result = true;
    if (this->day != other.day || this->month != other.month || this->year != other.year)
    {
        result = false;
    }
    return result;
}

bool Date::operator>(const Date &other)
{
    if (year < other.year)
    {
        return true;
    }
    else if (year > other.year)
    {
        return false;
    }
    else
    {
        // Years are equal, compare months
        if (month < other.month)
        {
            return true;
        }
        else if (month > other.month)
        {
            return false;
        }
        else
        {
            // Months are equal, compare days
            return day < other.day;
        }
    }
}

bool Date::operator<(const Date &other)
{
    return !(operator>(other) || operator==(other));
}

int Date::getDay()
{
    return this->day;
}
int Date::getMonth()
{
    return this->month;
}
int Date::getYear()
{
    return this->year;
}
void Date::setDay(int day)
{
    if (day < 1 || day > 30)
    {
        day = 0;
    }
    this->day = day;
}
void Date::setMonth(int month)
{
    if (month < 1 || month > 12)
    {
        month = 0;
    }
    this->month = month;
}
void Date::setYear(int year)
{
    this->year = year;
}

ostream &operator<<(ostream &os, const Date &dt)
{
    os << dt.day << '/' << dt.month << '/' << dt.year;
    return os;
}
#endif