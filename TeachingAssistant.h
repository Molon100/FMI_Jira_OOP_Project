#pragma once
#include "User.h"

class TeachingAssistant : public User
{
	// Inherited via User
	std::unique_ptr<User> clone() const override;
	void help() const override;
	void viewProfile() const override;
};