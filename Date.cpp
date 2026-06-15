#include "Date.h"
#include <stdexcept>

void Date::setMonth(unsigned month)
{
	if (month <= 0 || month > 12)
	{
		throw std::out_of_range("Month has to be between 1 and 12!");
	}
}

void Date::setDay(unsigned day)
{
	if (day <= 0 || day > 31) 
	{
		throw std::out_of_range("Invalid day!");
	}

}


void Date::setYear(unsigned year)
{
	if (year < 2026)
	{
		throw std::out_of_range("Cannot be a previous year!");
	}
}

Date::Date(unsigned day, unsigned month, unsigned year)
{
	setYear(year);
	setMonth(month);
	setDay(day);
}

std::ostream& operator<<(std::ostream& os, const Date& date)
{
	os << "D: " << date.day << " M: " << date.month << " Y: " << date.year << std::endl;
	return os;
}
