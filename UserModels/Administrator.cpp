#include "Administrator.h"

Administrator::Administrator(const std::string& username, const std::string& password) : User(username, password, Role::Administrator)
{
}

Administrator* Administrator::getInstance()
{
    static Administrator* instance = nullptr;
	if (instance == nullptr)
	{
		instance = new Administrator("admin","admin");
	}
	return instance;
}

std::unique_ptr<User> Administrator::clone() const
{
	return nullptr;
    // exception
}