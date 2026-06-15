#include "JoinProjectCommand.h"
#include "JiraSystem.h"

void JoinProjectCommand::execute(std::vector<std::string> args, JiraSystem& system)
{
	if (system.getCurrentUser()->getRole() != Role::Student)
	{
		//exc
	}

}

std::unique_ptr<Command> JoinProjectCommand::clone() const
{
    return std::make_unique<JoinProjectCommand>(*this);
}

JoinProjectCommand::JoinProjectCommand() : Command("join-project")
{
}
