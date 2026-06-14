#include "Administrator.h"

Administrator::Administrator(const std::string& username, const std::string& password) : User(username, password, Role::Administrator)
{
}

Administrator& Administrator::getInstance()
{
    static Administrator instance("admin", "123123");
    return instance;
}

//std::unique_ptr<User> Administrator::clone() const
//{
//	return nullptr;
//    // exception
//}