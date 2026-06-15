#pragma once
#include <string>

unsigned fromCharToNum(char ch)
{
	return ch - '0';
}

unsigned fromStringToNum(const std::string& str)
{
	unsigned num = 0;
	for (size_t i = 0; i < str.length(); i++)
	{
		num += fromCharToNum(str[i]);
		num *= 10;
	}
	num /= 10;
	return num;
}