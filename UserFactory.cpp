#include "UserFactory.h"

std::unique_ptr<User> UserFactory::makeUser(const std::string& username, const std::string& password, const Role& role)
{
    return std::make_unique<User>(username, password, role);
}
