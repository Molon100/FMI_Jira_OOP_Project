#include "ApproveTaskCommand.h"
#include "JiraSystem.h"
#include "Utils.h"

void ApproveTaskCommand::execute(std::vector<std::string> args, JiraSystem& system)
{
	if (!(system.getCurrentUser()->getRole() == Role::TeachingAssistant || system.getCurrentUser()->getRole() == Role::Lecturer))
	{
		throw std::invalid_argument("You need to be a Teaching Assistant or Lecturer");
	}
	unsigned taskId = fromStringToNum(args[1]);
	Task* task = system.findTaskWithId(taskId);
	task->approve();
}

std::unique_ptr<Command> ApproveTaskCommand::clone() const
{
    return std::make_unique<ApproveTaskCommand>(*this);
}

ApproveTaskCommand::ApproveTaskCommand() : Command("approve-task")
{
}
