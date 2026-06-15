#include "Command.h"
#include "JiraSystem.h"

const std::string& Command::getName() const
{
	return commandName;
}

Command::Command(const std::string& name) : commandName(name)
{
}