#include "Project.h"

Project::Project(const std::string& name, const std::string& description) : 
	name(name), description(description), startDate(Date::getCurrentDate()), status(ProjectStatus::Active)
{
}

Project::Project(const std::string& name, const std::string& description, const Date& startDate, ProjectStatus status)
	: name(name), description(description), startDate(startDate), status(status)
{
}

Project::Project(const std::string& name) 
	: name(name), description("none"), startDate(Date::getCurrentDate()), status(ProjectStatus::Active)
{
}

Project::Project(const std::string& name, ProjectStatus status)
	: name(name), description("none"), startDate(Date::getCurrentDate()), status(status)
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

const std::string& Project::getDesc() const
{
	return description;
}

const Date& Project::getDate() const
{
	return startDate;
}

std::vector<std::shared_ptr<User>> Project::getUsers() const
{
	return users;
}

std::vector<std::shared_ptr<Task>> Project::getTasks() const
{
	return tasks;
}

std::vector<std::shared_ptr<Stage>> Project::getStages() const
{
	return stages;
}

const ProjectStatus& Project::getStatus() const
{
	return status;
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
