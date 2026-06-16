#include "AssignTaskCommand.h"
#include "JiraSystem.h"
#include "Utils.h"

void AssignTaskCommand::execute(std::vector<std::string> args, JiraSystem& system)
{
	if (system.getCurrentUser()->getRole() != Role::Student)
	{
		//exc
	}
	unsigned id = fromStringToNum(args[1]);
	Task* task = system.findTaskWithId(id);
	task->assignUserInCharge(system.getCurrentUser());
}

std::unique_ptr<Command> AssignTaskCommand::clone() const
{
    return std::make_unique<AssignTaskCommand>(*this);
}

AssignTaskCommand::AssignTaskCommand() : Command("assign-task")
{
}
