#pragma once
#include "User.h"

class Administrator : public User
{

	Administrator(const std::string& username, const std::string& password);
public:
	Administrator(const Administrator& other) = delete;
	Administrator& operator=(const Administrator& other) = delete;
	static Administrator* getInstance();
	std::unique_ptr<User> clone() const override;
};