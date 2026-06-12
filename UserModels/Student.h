#pragma once
#include "User.h"

class Student : public User
{
public:
	std::unique_ptr<User> clone() const override;
	Student(const std::string& username, const std::string& password);
};
