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
	static Date getCurrentDate();

	Date(unsigned day, unsigned month, unsigned year);
	unsigned getDay() const;
	unsigned getMonth() const;
	unsigned getYear() const;
	bool isValidDate() const;
	friend std::ostream& operator<<(std::ostream& os, const Date& date);

	Date();
};