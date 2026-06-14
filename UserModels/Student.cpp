#include "Student.h"

std::unique_ptr<User> Student::clone() const
{
	return std::make_unique<Student>(*this);
}

Student::Student(const std::string& username, const std::string& password) : User(username, password, Role::Student)
{
}
