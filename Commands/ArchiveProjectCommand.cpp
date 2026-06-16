#include "ArchiveProjectCommand.h"
#include "JiraSystem.h"
#include <stdexcept>


void ArchiveProjectCommand::execute(std::vector<std::string> args, JiraSystem& system)
{
	if (system.getCurrentUser()->getRole() != Role::Administrator)
	{
		throw std::invalid_argument("You need to be an Admin");
	}
	std::string projectName = args[1];
	Project* project = system.findProjectByName(projectName);
	project->archive();
}

std::unique_ptr<Command> ArchiveProjectCommand::clone() const
{
    return std::make_unique<ArchiveProjectCommand>(*this);
}

ArchiveProjectCommand::ArchiveProjectCommand() : Command("archive-project")
{
}
