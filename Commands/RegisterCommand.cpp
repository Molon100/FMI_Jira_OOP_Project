#include "RegisterCommand.h"
#include "JiraSystem.h"
#include <stdexcept>

void RegisterCommand::execute(std::vector<std::string> args, JiraSystem& system)
{
	if (system.getCurrentUser()->getRole() != Role::Administrator)
	{
		throw std::invalid_argument("You need to be an Admin");

	}
	std::string username = args[1];
	std::string password = args[2];
	Role role = stringToRole(args[3]);
	if (role == Role::Administrator)
	{
		throw std::invalid_argument("Cannot have more than one Admin");

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
