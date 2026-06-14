#pragma once
#include <vector>
#include <memory>
#include "Role.h"

class JiraSystem;

class Command
{
protected:
	std::vector<Role> rolePremissions;
	std::string commandName;
public:
	virtual void execute(std::vector<std::string> args,JiraSystem& system) = 0;
	virtual std::unique_ptr<Command> clone() const = 0;
	virtual ~Command() = default;

	const std::string& getName() const;
	Command(const std::vector<Role>& rolePremissions, const std::string& name);
};