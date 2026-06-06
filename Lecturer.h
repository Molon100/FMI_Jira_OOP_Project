#pragma once
#include "User.h"

class Lecturer : public User
{
public:
	Lecturer(const std::string& username, const std::string& password);
	std::unique_ptr<User> clone() const override;
	void help() const override;
	void viewProfile() const override;
};