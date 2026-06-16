#include "AddCommentCommand.h"
#include "JiraSystem.h"
#include "Utils.h"

void AddCommentCommand::execute(std::vector<std::string> args, JiraSystem& system)
{
	if (system.getCurrentUser()->getRole() != Role::Student)
	{
		throw std::invalid_argument("You need to be a Student");

	}
	unsigned taskId = fromStringToNum(args[1]);
	std::cout << "Comment: ";
	std::string input;
	std::getline(std::cin, input);
	std::unique_ptr<Comment> comment = std::make_unique<Comment>(system.getCurrentUser()->getUsername(), input);
	Task* task = system.findTaskWithId(taskId);
	task->addComment(std::move(comment));
}

std::unique_ptr<Command> AddCommentCommand::clone() const
{
    return std::make_unique<AddCommentCommand>(*this);
}

AddCommentCommand::AddCommentCommand() : Command("add-comment")
{
}
