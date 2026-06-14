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

	//const User* login(std::string username, std::string password) const;
	//bool logout(std::string username, std::string password) const;
	std::string help() const;
	std::string viewProfile() const;
	//void close() const;

	unsigned getId() const;
};

