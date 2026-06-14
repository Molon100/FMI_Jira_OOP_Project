#pragma once
#include <string>

enum class Role
{
	Student,
	TeachingAssistant,
	Lecturer,
	Administrator,
	General
};

inline std::string roleToString(const Role& role)
{
	switch (role)
	{
	case Role::Student:
		return "Student";
	case Role::TeachingAssistant:
		return "TeachingAssistant";
	case Role::Lecturer:
		return "Lecturer";
	case Role::Administrator:
		return "Administrator";
	default:
		return "Unknown";
		break;
	}
}

inline Role stringToRole(const std::string& str)
{
	if (str == "Student")
	{
		return Role::Student;
	}
	else if (str == "TeachingAssistant")
	{
		return Role::TeachingAssistant;
	}
	else if (str == "Lecturer")
	{
		return Role::Lecturer;
	}
	else if (str == "Administrator")
	{
		return Role::Administrator;
	}
}