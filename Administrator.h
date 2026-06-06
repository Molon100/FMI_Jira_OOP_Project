#pragma once
#include "User.h"

class Administrator : public User
{
	// Inherited via User
	std::unique_ptr<User> clone() const override;
	void help() const override;
	void viewProfile() const override;
};