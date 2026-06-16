#pragma once

#include "Command.h"

class SaveCommand : public Command
{
public:
	// Inherited via Command
	void execute(std::vector<std::string> args, JiraSystem& system) override;
	std::unique_ptr<Command> clone() const override;

	SaveCommand();
};