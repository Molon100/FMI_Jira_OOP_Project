#pragma once
#include "TeachingAssistant.h"

class Lecturer : public TeachingAssistant
{
public:
	Lecturer(const std::string& username, const std::string& password);
	std::unique_ptr<User> clone() const override;
};