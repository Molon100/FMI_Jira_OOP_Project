#include "UserFactory.h"

std::shared_ptr<User> UserFactory::makeUser(const std::string& username, const std::string& password, const Role& role)
{
    return std::make_shared<User>(username, password, role);
}
