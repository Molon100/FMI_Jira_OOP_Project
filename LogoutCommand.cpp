#include "LogoutCommand.h"
#include "JiraSystem.h"


void LogoutCommand::execute(std::vector<std::string> args, JiraSystem& system)
{
    system.unassignCurrentUser();
}

std::unique_ptr<Command> LogoutCommand::clone() const
{
    return std::make_unique<LogoutCommand>(*this);
}

LogoutCommand::LogoutCommand() : GeneralCommand("logout")
{
}
