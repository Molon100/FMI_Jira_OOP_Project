#include "FinalizeProjectCommand.h"
#include "JiraSystem.h"

void FinalizeProjectCommand::execute(std::vector<std::string> args, JiraSystem& system)
{
	if (system.getCurrentUser()->getRole() != Role::Lecturer)
	{
		throw std::invalid_argument("You need to be a Lecturer");
	}
	std::string projectName = args[1];
	Project* project = system.findProjectByName(projectName);
	project->finalize();
}

std::unique_ptr<Command> FinalizeProjectCommand::clone() const
{
    return std::make_unique<FinalizeProjectCommand>(*this);
}

FinalizeProjectCommand::FinalizeProjectCommand() : Command("finalize-project")
{
}
