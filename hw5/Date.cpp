#include "Date.h"
Date::Date(int day, int month, int year = 2024)
{
    try
    {
        setDay(day);
        setMonth(month);
        this->year = year;
    }
    catch (char *emsg)
    {
        cout << emsg << endl;
    }
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
void Date::setDay(int day) throw(char *)
{
    if (day < 1 || day > 31)
    {
        throw "day should be in the range 1-31";
    }
    this->day = day;
}
void Date::setMonth(int month) throw(char *)
{
    if (month < 1 || month > 12)
    {
        throw "month should be in the range 1-12";
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