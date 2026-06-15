#include "RegisterCommand.h"
#include "JiraSystem.h"

void RegisterCommand::execute(std::vector<std::string> args, JiraSystem& system)
{
	if (system.getCurrentUser()->getRole() != Role::Administrator)
	{
		//exc
	}
	std::string username = args[1];
	std::string password = args[2];
	Role role = stringToRole(args[3]);
	if (role == Role::Administrator)
	{
		//exc dupli admin
	}
	system.addUser(username, password, role);
}

std::unique_ptr<Command> RegisterCommand::clone() const
{
    return std::make_unique<RegisterCommand>(*this);
}

RegisterCommand::RegisterCommand() : Command("register")
{
}
