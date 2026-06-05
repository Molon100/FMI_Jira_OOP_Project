#pragma once
#include "User.h"

class Student : public User
{
	// Inherited via User
	void help() const override;
	void viewProfile() const override;
	std::unique_ptr<User> clone() const override;
};