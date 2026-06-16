#include "RemoveUserCommand.h"
#include "JiraSystem.h"


void RemoveUserCommand::execute(std::vector<std::string> args, JiraSystem& system)
{
	if (system.getCurrentUser()->getRole() != Role::Administrator)
	{
		//exc
	}
	std::string username = args[1];
	system.removeUser(username);
}

std::unique_ptr<Command> RemoveUserCommand::clone() const
{
    return std::make_unique<RemoveUserCommand>(*this);
}

RemoveUserCommand::RemoveUserCommand() : Command("remove-user")
{
}
