#include "ArchiveProjectCommand.h"
#include "JiraSystem.h"


void ArchiveProjectCommand::execute(std::vector<std::string> args, JiraSystem& system)
{
	if (system.getCurrentUser()->getRole() != Role::Administrator)
	{
		//exc
	}
}

std::unique_ptr<Command> ArchiveProjectCommand::clone() const
{
    return std::make_unique<ArchiveProjectCommand>(*this);
}

ArchiveProjectCommand::ArchiveProjectCommand() : Command("archive-project")
{
}
