#pragma once
#include <string>


class User
{
protected:
	static size_t numberOfUsers;
	unsigned id;
	std::string username;
	std::string password;
	void login(std::string username, std::string password) const;
	void logout(std::string username, std::string password) const;
	void help() const;
	void viewProfile() const;
	void close() const;
	
};