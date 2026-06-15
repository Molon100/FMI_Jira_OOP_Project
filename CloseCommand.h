#pragma once
#include "GeneralCommand.h"

class CloseCommand : public GeneralCommand
{
public:
	// Inherited via GeneralCommand
	void execute(std::vector<std::string> args, JiraSystem& system) override;
	std::unique_ptr<Command> clone() const override;

	CloseCommand();
};
