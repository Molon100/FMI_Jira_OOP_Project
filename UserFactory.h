#pragma once
#include "User.h"

class UserFactory
{
public:
	static std::unique_ptr<User> makeUser(const std::string& username, const std::string& password, const Role& role);
	UserFactory() = delete;
};