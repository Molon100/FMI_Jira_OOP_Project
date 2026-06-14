#include "CommandHeap.h"
#include "LoginCommand.h"

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
}
