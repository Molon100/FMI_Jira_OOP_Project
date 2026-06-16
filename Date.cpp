#include "Date.h"
#include <stdexcept>
#include <ctime>

void Date::setMonth(unsigned month)
{
	if (month <= 0 || month > 12)
	{
		this->month = 0;
	}
}

void Date::setDay(unsigned day)
{
	if (day <= 0 || day > 31) 
	{
		this->day = 0;
	}

}


void Date::setYear(unsigned year)
{
	if (year < 2026 || year >= 2999)
	{
		this->year = 0;
	}
}

Date Date::getCurrentDate()
{
	std::time_t now = std::time(nullptr);

	std::tm localTime{};
	localtime_s(&localTime, &now);

	int year = localTime.tm_year + 1900;
	int month = localTime.tm_mon + 1;
	int day = localTime.tm_mday;
	return Date(day, month, year);
}

Date::Date(unsigned day, unsigned month, unsigned year)
{
	setYear(year);
	setMonth(month);
	setDay(day);
}

unsigned Date::getDay() const
{
	return day;
}

unsigned Date::getMonth() const
{
	return month;
}

unsigned Date::getYear() const
{
	return year;
}

bool Date::isValidDate() const
{
	if (day == 0 || month == 0 || year == 0)
	{
		return false;
	}
	return true;
}

Date::Date() : day(), month(0), year(0)
{
}

std::ostream& operator<<(std::ostream& os, const Date& date)
{
	os << "D: " << date.day << " M: " << date.month << " Y: " << date.year << std::endl;
	return os;
}
