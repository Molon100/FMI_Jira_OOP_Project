#include "Project.h"

Project::Project(const std::string& name, const std::string& description) : 
	name(name), description(description), startDate(1,1,2026), status(ProjectStatus::Active)
{
}

Project::Project(const std::string& name) 
	: name(name), description(""), startDate(1, 1, 2026), status(ProjectStatus::Active)
{
}

Project::Project(const std::string& name, ProjectStatus status)
	: name(name), description(""), startDate(1, 1, 2026), status(status)
{
}


void Project::addUser(const User& user)
{
	users.push_back(std::make_shared<User>(user));
	std::cout << "is in proj";
}

void Project::addTask(std::shared_ptr<Task> task)
{
	tasks.push_back(task);
	std::cout << "is in proj";
}

const std::string& Project::getName() const
{
	return name;
}

bool Project::hasUser(unsigned id) const
{
	for (const auto& user : users)
	{
		if (user->getId() == id)
		{
			return true;
		}
	}
	return false;
}

void Project::listTasks() const
{
	for (const auto& task : tasks)
	{
		std::cout << *task << std::endl;
	}
}

Task* Project::findTask(unsigned id) const
{
	for (const auto& task : tasks)
	{
		if (task->getID() == id)
		{
			return task.get();
		}
	}
	return nullptr;
}

std::ostream& operator<<(std::ostream& os, const Project& project)
{
	os << project.name << ' ' << project.description << ' ' << project.startDate << ' '
		<< projectStatusToString(project.status) << std::endl;
	for (const auto& user : project.users)
	{
		os << user->getId() << ' ';
	}
	os << std::endl;
	for (const auto& task : project.tasks)
	{
		os << *task << ' ';
	}
	os << std::endl;
	for (const auto& stage : project.stages)
	{
		os << *stage << ' ';
	}
	os << std::endl;
	return os;
}
