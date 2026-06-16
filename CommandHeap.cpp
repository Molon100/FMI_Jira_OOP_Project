#include "CommandHeap.h"
#include "LoginCommand.h"
#include "LogoutCommand.h"
#include "ViewProfileCommand.h"
#include "CloseCommand.h"
#include "RegisterCommand.h"
#include "CreateProjectCommand.h"
#include "ArchiveProjectCommand.h"
#include "RemoveUserCommand.h"
#include "JoinProjectCommand.h"
#include "ListTasksCommand.h"
#include "ListProjectsCommand.h"
#include "CreateTaskCommand.h"
#include "SaveCommand.h"
#include "ChangeTaskStatusCommand.h"
#include "AddCommentCommand.h"
#include "ApproveTaskCommand.h"

#include <stdexcept>

Command* CommandHeap::findCommandByName(const std::string name) const
{
	for (const auto& command : commands)
	{
		if (command->getName() == name)
		{
			return command.get();
		}
	}
	throw std::invalid_argument("Command not found");
}

CommandHeap::CommandHeap()
{
	commands.push_back(LoginCommand().clone());
	commands.push_back(LogoutCommand().clone());
	commands.push_back(ViewProfileCommand().clone());
	commands.push_back(CloseCommand().clone());
	commands.push_back(RegisterCommand().clone());
	commands.push_back(CreateProjectCommand().clone());
	commands.push_back(ArchiveProjectCommand().clone());
	commands.push_back(RemoveUserCommand().clone());
	commands.push_back(JoinProjectCommand().clone());
	commands.push_back(ListTasksCommand().clone());
	commands.push_back(ListProjectsCommand().clone());
	commands.push_back(CreateTaskCommand().clone());
	commands.push_back(SaveCommand().clone());
	commands.push_back(ChangeTaskStatusCommand().clone());
	commands.push_back(AddCommentCommand().clone());
	commands.push_back(ApproveTaskCommand().clone());
}
