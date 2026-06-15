#include "CommandSystem.h"
#include "JiraSystem.h"
#include <iostream>

void CommandSystem::parseCommand(const std::string& command)
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

void CommandSystem::executeCommand(const std::string& name, JiraSystem& system) const
{
	Command* command = commandHeap.findCommandByName(name);
	command->execute(parsedCommand, system);
}

void CommandSystem::action(JiraSystem& system)
{
	std::cout << '>';
	std::string command;
	std::getline(std::cin, command);
	parseCommand(command);
	std::string commandName = parsedCommand[0];
	try
	{
	executeCommand(commandName, system);

	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
	}
}
