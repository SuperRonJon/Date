#include "Date.h"
#include <iostream>
#include <sstream>

using namespace std;

Date::Date()
{
    day = 0;
    month = january;
    year = 0;
}

Date::~Date()
{
    //dtor
}

Date::Date(const Date& other)
{
    day = other.day;
    month = other.month;
    year = other.year;
}

Date::Date(int y, Month m, int d)
{
    month = m;
    year = y;

    if(d > getDaysInMonth())
    {
        day = d - getDaysInMonth();
        incrementMonth();

    }
    else
        day = d;
}

Date::Date(int y, int m, int d)
{
    month = static_cast<Month>(m);
    year = y;

    if(d > getDaysInMonth())
    {
        day = d - getDaysInMonth();
        incrementMonth();

    }
    else
        day = d;
}

Date Date::operator=(const Date& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    day = rhs.day;
    month = rhs.month;
    year = rhs.year;
}

bool Date::operator<(const Date& other)
{
    if(year < other.year)
        return true;
    else if(year == other.year)
    {
        if(month < other.month)
            return true;
        else if(month == other.month)
        {
            if(day < other.day)
                return true;
            else
                return false;
        }
        else
            return false;
    }
    else
        return false;
}

bool operator>(Date& lhs,Date& rhs)
{
    return !(lhs < rhs);
}

Date Date::operator++(int)
{
    incrementDay();
}

int Date::getDay()
{
    return day;
}

void Date::setDay(int d)
{
    day = d;
}

Date::Month Date::getMonth()
{
    return month;
}

void Date::setMonth(Month m)
{
    month = m;
}

int Date::getYear()
{
    return year;
}

void Date::setYear(int y)
{
    year = y;
}

string Date::toString()
{
    stringstream ss;
    ss << month << "/" << day << "/" << year;
    return ss.str();
}

int Date::getDaysInMonth()
{
    if(month == Date::september || month == Date::april || month == Date::june || month == Date::november)
        return 30;
    else if(month == Date::february)
    {
        if(isLeapYear())
            return 29;
        else
            return 28;
    }
    else
        return 31;

}

bool Date::isLeapYear()
{
    if(year % 4 == 0)
    {
        if(year % 100 == 0)
        {
            if(year % 400 == 0)
                return true;
            else
                return false;
        }
        else
            return true;
    }
    else
        return false;
}

void Date::incrementMonth()
{
    if(month == Date::december)
    {
        month = Date::january;
        incrementYear();
    }
    else
    {
        int monthInt = static_cast<int>(month);
        monthInt++;
        month = static_cast<Date::Month>(monthInt);
    }
}

void Date::incrementYear()
{
    year++;
}

void Date::incrementDay()
{
    if(day >= getDaysInMonth())
    {
        day = 1;
        incrementMonth();
    }
    else
        day++;
}

void Date::print()
{
    cout << toString();
}

