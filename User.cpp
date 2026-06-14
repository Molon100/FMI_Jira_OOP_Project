#include "User.h"
#include <format>

size_t User::numberOfUsers = 0;

User::User(const std::string& username, const std::string& password, const Role& role) : username(username), password(password), role(role)
{
	numberOfUsers++;
	id = numberOfUsers;

}


std::string User::viewProfile() const
{
	return std::format("Id: {};\nUsername: {}\nRole: {}\n", id, username, roleToString(role));
}
