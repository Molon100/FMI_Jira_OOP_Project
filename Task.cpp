#include "Task.h"

size_t Task::numberOfTasks = 0;

Task::Task(const TaskType& type, const Priority& priority)
	: title(""), description(""), type(type), priority(priority), status(TaskStatus::ToDo),
	deadline(31,12,2026),  points(0), grade(0)
{
	numberOfTasks++;
	id = numberOfTasks;

}

void Task::assignUserInCharge(const User* user)
{
	userInCharge = user;
}

void Task::setTitle(const std::string& title)
{
	this->title = title;
}

void Task::setDesc(const std::string& desc)
{
	this->description = desc;
}

unsigned Task::getID() const
{
	return id;
}

std::ostream& operator<<(std::ostream& os, const Task& task)
{
	os << task.id << ' ' << task.title << ' ' << task.description << ' ' << taskTypeToString(task.type) << ' '
		<< priotityToString(task.priority) << ' ' << taskStatusToString(task.status) << ' ' 
		<< task.deadline << ' ' << task.points << ' ' << task.grade << std::endl;
	for (const auto& comment : task.comments)
	{
		os << comment << std::endl;
	}
	for (const auto& change : task.historyOfChanges)
	{
		os << change << std::endl;
	}
	return os;
}
