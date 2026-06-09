#pragma once

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
};