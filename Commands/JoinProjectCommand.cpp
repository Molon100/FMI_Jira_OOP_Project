#include "JoinProjectCommand.h"
#include "JiraSystem.h"
#include <stdexcept>

void JoinProjectCommand::execute(std::vector<std::string> args, JiraSystem& system)
{
	if (system.getCurrentUser()->getRole() != Role::Student)
	{
		throw std::invalid_argument("You need to be a Student");

	}
	std::string projectName = args[1];
	Project* project = system.findProjectByName(projectName);
	project->addUser(*system.getCurrentUser());
}

std::unique_ptr<Command> JoinProjectCommand::clone() const
{
    return std::make_unique<JoinProjectCommand>(*this);
}

JoinProjectCommand::JoinProjectCommand() : Command("join-project")
{
}
