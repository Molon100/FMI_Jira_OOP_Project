#pragma once
#include "GeneralCommand.h"

class LoginCommand : public GeneralCommand
{
public:
	// Inherited via GeneralCommand
	void execute(std::vector<std::string> commandArgs,JiraSystem& system) override;
	std::unique_ptr<Command> clone() const override;

	LoginCommand();
};