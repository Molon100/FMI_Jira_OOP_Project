#include "CommandHeap.h"
#include "LoginCommand.h"
#include "LogoutCommand.h"
#include "ViewProfileCommand.h"
#include "CloseCommand.h"

Command* CommandHeap::findCommandByName(const std::string name) const
{
	for (const auto& command : commands)
	{
		if (command->getName() == name)
		{
			return command.get();
		}
	}return nullptr;
}

CommandHeap::CommandHeap()
{
	commands.push_back(LoginCommand().clone());
	commands.push_back(LogoutCommand().clone());
	commands.push_back(ViewProfileCommand().clone());
	commands.push_back(CloseCommand().clone());
}
