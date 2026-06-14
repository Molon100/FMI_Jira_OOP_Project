#include "Command.h"
#include "JiraSystem.h"

const std::string& Command::getName() const
{
	return commandName;
}

Command::Command(const std::vector<Role>& rolePremissions, const std::string& name) : rolePremissions(rolePremissions), commandName(name)
{
}