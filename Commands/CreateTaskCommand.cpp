#include "CreateTaskCommand.h"
#include "JiraSystem.h"
#include <stdexcept>



void CreateTaskCommand::execute(std::vector<std::string> args, JiraSystem& system)
{
	if (system.getCurrentUser()->getRole() != Role::Student)
	{
		throw std::invalid_argument("You need to be a Student");

	}
	std::string projectName = args[1];
	std::string typeStr = args[2];
	std::string priorityStr = args[3];
	TaskType type = stringToTaskType(typeStr);
	Priority priority = stringToPriority(priorityStr);
	Project* project = system.findProjectByName(projectName);
	auto q = std::make_shared<Task>(type, priority);
	project->addTask(q);
	system.addTask(q);
	std::cout << "Title: ";
	std::string input;
	std::getline(std::cin, input);
	const User* user = system.getCurrentUser();
	q->setTitle(input, user->getUsername());
	std::cout << "Desc: ";
	std::getline(std::cin, input);
	q->setDesc(input, user->getUsername());
}

std::unique_ptr<Command> CreateTaskCommand::clone() const
{
    return std::make_unique<CreateTaskCommand>(*this);
}

CreateTaskCommand::CreateTaskCommand() : Command("create-task")
{
}
