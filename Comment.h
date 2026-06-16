#pragma once
#include <string>

class Comment
{
	std::string author;
	std::string content;
public:

	Comment(const std::string& author, const std::string& content);

	friend std::ostream& operator<<(std::ostream& os, const Comment& comment);
};