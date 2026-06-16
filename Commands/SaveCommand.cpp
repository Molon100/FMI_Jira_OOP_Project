#include "SaveCommand.h"
#include "JiraSystem.h"
#include <stdexcept>

void SaveCommand::execute(std::vector<std::string> args, JiraSystem& system)
{
	if (system.getCurrentUser()->getRole() != Role::Administrator)
	{
		throw std::invalid_argument("You need to be an Admin");

	}
	system.save();
}

std::unique_ptr<Command> SaveCommand::clone() const
{
    return std::make_unique<SaveCommand>(*this);
}

SaveCommand::SaveCommand() : Command("save")
{
}
