#pragma once
#include "User.h"

class Student : public User
{
public:
	void help() const override;
	void viewProfile() const override;
	std::unique_ptr<User> clone() const override;
	Student(const std::string& username, const std::string& password);
};
