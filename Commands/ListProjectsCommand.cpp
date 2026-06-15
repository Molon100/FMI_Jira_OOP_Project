#include "ListProjectsCommand.h"
#include "JiraSystem.h"


void ListProjectsCommand::execute(std::vector<std::string> args, JiraSystem& system)
{
    if (system.getCurrentUser()->getRole() != Role::Student)
    {
        //exc
    }
    system.listAllProjectForCurrentUser();
}

std::unique_ptr<Command> ListProjectsCommand::clone() const
{
    return std::make_unique<ListProjectsCommand>(*this);
}

ListProjectsCommand::ListProjectsCommand() : Command("list-projects")
{
}
