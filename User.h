#pragma once
#include <string>
#include <memory>
#include "Role.h"
#include <iostream>


class User
{
protected:
	static size_t numberOfUsers;
	unsigned id;
	std::string username;
	std::string password; 
	Role role;

	void copyFrom(const User& other);
	void free();
public:
	User(const std::string& username, const std::string& password, const Role& role);
	User(const User& other);
	User& operator=(const User& other);

	unsigned getId() const;
	bool checkPassword(const std::string& password) const;
	const std::string& getUsername() const;
	Role getRole() const;

	friend std::ostream& operator<<(std::ostream& os, const User& user);
	friend std::istream& operator>>(std::istream& is, User& user);
};

