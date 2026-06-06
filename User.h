#pragma once
#include <string>
#include <memory>
#include "Role.h"


class User
{
protected:
	static size_t numberOfUsers;
	unsigned id;
	std::string username;
	std::string password;
	Role role;
public:
	User(const std::string& username, const std::string& password, const Role& role);
	virtual std::unique_ptr<User> clone() const = 0;
	const User* login(std::string username, std::string password) const;
	bool logout(std::string username, std::string password) const;
	virtual void help() const = 0;
	virtual void viewProfile() const = 0;
	void close() const;
	virtual ~User() = default;
};