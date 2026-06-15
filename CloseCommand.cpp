#include "CloseCommand.h"
#include "JiraSystem.h"

void CloseCommand::execute(std::vector<std::string> args, JiraSystem& system)
{
	system.stopRunning();
}

std::unique_ptr<Command> CloseCommand::clone() const
{
	return std::make_unique<CloseCommand>(*this);
}

CloseCommand::CloseCommand() : Command("close")
{
}
