#include "CreateProjectCommand.h"
#include "JiraSystem.h"

void CreateProjectCommand::execute(std::vector<std::string> args, JiraSystem& system)
{
	if (system.getCurrentUser()->getRole() != Role::Administrator)
	{
		//exc
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
