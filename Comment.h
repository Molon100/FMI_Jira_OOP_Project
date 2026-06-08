#pragma once
#include <string>

class Comment
{
	std::string author;
	std::string content;
	std::string data;
public:

	Comment(const std::string& author, const std::string& content, const std::string& data);
};