#include "User.h"
#include <format>

size_t User::numberOfUsers = 0;

void User::copyFrom(const User& other)
{
	id = other.id;
	username = other.username;
	password = other.password;
	role = other.role;

}

void User::free()
{
	id = 0;
	username = "";
	password = "";
	role = Role::General;
}

User::User(const std::string& username, const std::string& password, const Role& role) : username(username), password(password), role(role)
{
	numberOfUsers++;
	id = numberOfUsers;

}

User::User(const User& other)
{
	copyFrom(other);
}

User& User::operator=(const User& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
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

Role User::getRole() const
{
	return role;
}

std::ostream& operator<<(std::ostream& os, const User& user)
{
	return os << user.id << ' ' << user.username << ' ' <<	roleToString(user.role) << std::endl;
}

std::istream& operator>>(std::istream& is, User& user)
{
	return is >> user.id >> user.username;
}
