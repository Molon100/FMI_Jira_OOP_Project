#include "Comment.h"
#include <iostream>

Comment::Comment(const std::string& author, const std::string& content) : author(), content(content)
{
}

std::ostream& operator<<(std::ostream& os, const Comment& comment)
{
	return os << comment.content << ' ' << comment.author  << std::endl;
}
