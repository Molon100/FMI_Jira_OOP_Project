#pragma once
#include <string>
#include "Role.h"


class User
{
protected:
	static size_t numberOfUsers;
	unsigned id;
	std::string username;
	std::string password;
	Role role;

	const User* login(std::string username, std::string password) const;
	bool logout(std::string username, std::string password) const;
	virtual void help() const = 0;
	virtual void viewProfile() const = 0;
	void close() const;
	
	virtual ~User() = default;
};