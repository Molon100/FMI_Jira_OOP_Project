#pragma once
#include "Command.h"

class LogoutCommand : public Command
{
public:
	// Inherited via GeneralCommand
	void execute(std::vector<std::string> args, JiraSystem& system) override;
	std::unique_ptr<Command> clone() const override;

	LogoutCommand();
};