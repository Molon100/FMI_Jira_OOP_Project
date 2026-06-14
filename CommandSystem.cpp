#include "CommandSystem.h"

void CommandSystem::parseCommand(std::string command)
{
	parsedCommand.clear();
	int i = 0;
	int prev = 0;
	for (size_t i = 0; i < command.length(); i++)
	{
		if (command[i] == ' ')
		{
			parsedCommand.push_back(command.substr(prev, i - prev));
			prev = i + 1;
		}
	}
	parsedCommand.push_back(command.substr(prev));
}
