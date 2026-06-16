#include "CreateProjectCommand.h"
#include "JiraSystem.h"
#include <stdexcept>


void CreateProjectCommand::execute(std::vector<std::string> args, JiraSystem& system)
{
	if (system.getCurrentUser()->getRole() != Role::Administrator)
	{
		throw std::invalid_argument("You need to be an Admin");

	}
	std::string projectName = args[1];
	system.addProject(projectName);
}

std::unique_ptr<Command> CreateProjectCommand::clone() const
{
    return std::make_unique<CreateProjectCommand>(*this);
}

CreateProjectCommand::CreateProjectCommand() : Command("create-project")
{
}
