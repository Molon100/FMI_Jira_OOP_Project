#include "Task.h"

size_t Task::numberOfTasks = 0;

Task::Task(unsigned id, const std::string& title, const std::string& description, const TaskType& type, const Priority& priority)
	: title(title), description(description), type(type), priority(priority), deadline(31,12,2026),  points(0), grade(0)
{
	numberOfTasks++;
	id = numberOfTasks;

}

void Task::assignUserInCharge(const User& user)
{
	userInCharge = std::make_shared<User>(user);
}
