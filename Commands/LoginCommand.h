#pragma once
#include "Command.h"

class LoginCommand : public Command
{
public:
	// Inherited via GeneralCommand
	void execute(std::vector<std::string> commandArgs,JiraSystem& system) override;
	std::unique_ptr<Command> clone() const override;

	LoginCommand();
};