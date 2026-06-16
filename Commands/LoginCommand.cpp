#include "LoginCommand.h"
#include "JiraSystem.h"
#include <stdexcept>

void LoginCommand::execute(std::vector<std::string> commandArgs, JiraSystem& system)
{
    if (system.getCurrentUser())
    {
        throw std::invalid_argument("You need to logout first");
    }
    std::string username = commandArgs[1];
    std::string password = commandArgs[2];
    const User* user = system.findUserByUsername(username);
    if (!user->checkPassword(password))
    {
        throw std::invalid_argument("Password does not match");
    }
    system.assignCurrentUser(user);
}

std::unique_ptr<Command> LoginCommand::clone() const
{
    return std::make_unique<LoginCommand>(*this);
}

LoginCommand::LoginCommand() : Command("login")
{
}

