#include "SaveCommand.h"
#include "JiraSystem.h"

void SaveCommand::execute(std::vector<std::string> args, JiraSystem& system)
{
	if (system.getCurrentUser()->getRole() != Role::Administrator)
	{
		//exc
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
