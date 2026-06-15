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

unsigned User::getId() const
{
	return id;
}

bool User::checkPassword(const std::string& password) const
{
	return password == this->password;
}

const std::string& User::getUsername() const
{
	return username;
}

std::ostream& operator<<(std::ostream& os, const User& user)
{
	return os << user.id << ' ' << user.username << ' ' <<	roleToString(user.role) << std::endl;
}
