#pragma once

#include "GeneralCommand.h"

class ViewProfileCommand : public GeneralCommand
{
public:
	// Inherited via GeneralCommand
	void execute(std::vector<std::string> args, JiraSystem& system) override;
	std::unique_ptr<Command> clone() const override;

	ViewProfileCommand();
};