#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "Date.h"

// public member variable MONTHS[] w/ initialization
std::string const Date::MONTHS[12] = {"JANUARY", "FEBRUARY", "MARCH", "APRIL", 
                                      "MAY", "JUNE", "JULY", "AUGUST", 
                                      "SEPTEMBER", "OCTOBER", "NOVEMBER", 
                                      "DECEMBER"};

void Date::setDay(int d)        // mutator definitions
    { day = d; }
void Date::setMonth(int m)
    { month = m; }
void Date::setYear(int y)
    { year = y; }

int Date::getDay() const        // accessor definitions
    { return day; }
int Date::getMonth() const
    { return month; }
int Date::getYear() const
    { return year; }

// prints date with formatted provided using stringstream
std::string Date::print()
{
    std::stringstream ss;
    ss << std::left << std::setw(10) << MONTHS[month - 1];
    ss << std::left << std::setw(3) << day; 
    ss << std::left << std::setw(5) << year;
    return ss.str();
}

// compares two dates passed through compare()
bool Date::compare(const Date& d1, const Date& d2)
{
    if (d1.getYear() == d2.getYear())       // compares years
    {
        if (d1.getMonth() == d2.getMonth())     // compares months
        {
         // compares days and returns the two dates in order via day comparison
            if (d1.getDay() == d2.getDay())
                { return d1.getDay() < d2.getDay(); }
        }

     // otherwise, returns the two dates in order via month comparison   
        return d1.getMonth() < d2.getMonth();
    }

 // otherwise, returns the two dates in order via year comparison
    return d1.getYear() < d2.getYear();
}