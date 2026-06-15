#pragma once
#include <iostream>

class Date
{
	unsigned day;
	unsigned month;
	unsigned year;
	void setDay(unsigned day);
	void setMonth(unsigned month);
	void setYear(unsigned year);
public:
	Date(unsigned day, unsigned month, unsigned year);

	friend std::ostream& operator<<(std::ostream& os, const Date& date);
};