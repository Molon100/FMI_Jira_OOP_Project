#include "LoginCommand.h"
#include "JiraSystem.h"

void LoginCommand::execute(std::vector<std::string> commandArgs, JiraSystem& system)
{
    std::string username = commandArgs[1];
    std::string password = commandArgs[2];
    const User* user = system.findUserByUsername(username);
    if (user->checkPassword(password))
    {
        system.assignCurrentUser(user);
    }
}

std::unique_ptr<Command> LoginCommand::clone() const
{
    return std::make_unique<LoginCommand>(*this);
}

LoginCommand::LoginCommand() : Command("login")
{
}

