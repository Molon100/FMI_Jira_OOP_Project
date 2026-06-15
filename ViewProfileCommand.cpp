#include "ViewProfileCommand.h"
#include "JiraSystem.h"
#include <iostream>

void ViewProfileCommand::execute(std::vector<std::string> args, JiraSystem& system)
{
	std::cout << *system.getCurrentUser();
}

std::unique_ptr<Command> ViewProfileCommand::clone() const
{
	return std::make_unique<ViewProfileCommand>(*this);
}

ViewProfileCommand::ViewProfileCommand() : GeneralCommand("view-profile")
{
}
