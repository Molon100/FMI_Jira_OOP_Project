#include "ListTasksCommand.h"
#include "JiraSystem.h"

void ListTasksCommand::execute(std::vector<std::string> args, JiraSystem& system)
{
    if (system.getCurrentUser()->getRole() != Role::Student)
    {
        //exc
    }

    system.listTasksForCurrentUser();
}

std::unique_ptr<Command> ListTasksCommand::clone() const
{
    return std::make_unique<ListTasksCommand>(*this);
}

ListTasksCommand::ListTasksCommand()
    : Command("list-tasks")
{
}