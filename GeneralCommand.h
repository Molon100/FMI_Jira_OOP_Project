#pragma once
#include "Command.h"

class GeneralCommand : public Command
{
public:
	virtual void execute(std::vector<std::string> args,JiraSystem& system) = 0;
	virtual std::unique_ptr<Command> clone() const = 0;
	virtual ~GeneralCommand() = default;

	GeneralCommand(const std::string& name);
};