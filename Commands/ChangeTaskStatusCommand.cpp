#include "ChangeTaskStatusCommand.h"
#include "JiraSystem.h"
#include "Utils.h"
#include <stdexcept>



void ChangeTaskStatusCommand::execute(std::vector<std::string> args, JiraSystem& system)
{
	if (system.getCurrentUser()->getRole() != Role::Student)
	{
		throw std::invalid_argument("You need to be a Student");

	}
	unsigned taskId = fromStringToNum(args[1]);
	std::string taskStatusStr = args[2];
	TaskStatus status = stringToTaskStatus(taskStatusStr);
	if (status == TaskStatus::InReview || status == TaskStatus::Done)
	{
		throw new std::invalid_argument("Status cannot be reviewd by Student, or pass without review");
	}
	Task* task = system.findTaskWithId(taskId);
	task->changeStatus(status, system.getCurrentUser()->getUsername());
}

std::unique_ptr<Command> ChangeTaskStatusCommand::clone() const
{
    return std::make_unique<ChangeTaskStatusCommand>(*this);
}

ChangeTaskStatusCommand::ChangeTaskStatusCommand() : Command("change-status")
{
}
