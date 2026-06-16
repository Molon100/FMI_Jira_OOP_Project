#include "JiraSystem.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Utils.h"
#include <stdexcept>


void JiraSystem::run()
{
	if (isNew())
	{
		createNew();
		std::cin.ignore();
	}
	else
	{
		loadUsers();
		loadTasks();
		loadProjects();
	}
	while (isRunning)
	{
		cs.action(*this);
	}
}

void JiraSystem::stopRunning()
{
	isRunning = false;
}


Project* JiraSystem::findProjectByName(const std::string& projectName) const
{
	for (size_t i = 0; i < projects.size(); i++)
	{
		if (projects[i]->getName() == projectName)
		{
			return projects[i].get();
		}
	}
	throw std::invalid_argument("No project with that name");
}

Task* JiraSystem::findTaskWithId(unsigned id) const
{
	for (const auto& task : tasks)
	{
		if (task->getID() == id)
		{
			return task.get();
		}
	}
	throw std::invalid_argument("No task with that id");
}

const User* JiraSystem::findUserByUsername(const std::string& username) const
{
	for (size_t i = 0; i < users.size(); i++)
	{
		if (users[i]->getUsername() == username)
		{
			return users[i].get();
		}
	}
	throw std::invalid_argument("No user with that username");
}

User* JiraSystem::findUserById(unsigned id) const
{
	for (size_t i = 0; i < users.size(); i++)
	{
		if (users[i]->getId() == id)
		{
			return users[i].get();
		}
	}
	throw std::invalid_argument("No user with that id");
}

const User* JiraSystem::getCurrentUser() const
{
	return currentUser;
}

void JiraSystem::assignCurrentUser(const User* user)
{
	currentUser = user;
}

void JiraSystem::listAllProjectForCurrentUser() const
{
	const User* user = getCurrentUser();
	for (const auto& project : projects)
	{
		if (project->hasUser(user->getId()))
		{
			std::cout << *project << std::endl;
		}
	}
}

void JiraSystem::listTasksForCurrentUser() const
{
	const User* user = getCurrentUser();
	for (const auto& project : projects)
	{
		if (project->hasUser(user->getId()))
		{
			project->listTasks();
		}
	}
}

void JiraSystem::addProject(const std::string& name)
{
	projects.push_back(std::make_unique<Project>(name));
}

void JiraSystem::addTask(const std::shared_ptr<Task>& task)
{
	tasks.push_back(task);
}

void JiraSystem::save() const
{
	std::ofstream file1("Tasks.txt");
	std::ofstream file2("Projects.txt");
	if (!file2.is_open() || !file1.is_open())
	{
		//exc
	}
	for (const auto& task : tasks)
	{
		const Date* date = &task->getDate();
		file1 << task->getID() << ' ' << task->getTitle() << ' ' << task->getDesc() << ' ' << taskTypeToString(task->getType()) << ' ' <<
			 priotityToString(task->getPriority()) << ' ' << taskStatusToString(task->getStatus()) << ' ' << date->getDay() << ' '
			<< date->getMonth() << ' ' << date->getYear() << ' ' << task->getPoints() << ' ' << task->getGrade() << std::endl;
		//for (const auto& comment : task->getComments())
		//{
		//	file1 << *comment;
		//}
		//file1 << std::endl;
		//file1 << '.';
		//for (const auto& change : task->getChanges())
		//{
		//	file1 << change << std::endl;
		//}
		//file1 << '.' << std::endl;

	}
	file1 << '/' << std::endl;
	for (const auto& project : projects)
	{
		const Date* date = &project->getDate();
		file2 << project->getName() << ' ' << project->getDesc() << ' ' << date->getDay() << ' '
			<< date->getMonth() << ' ' << date->getYear() << ' ' << projectStatusToString(project->getStatus()) << std::endl;
		for (const auto& user : project->getUsers())
		{
			file2 << user->getId() << ' ';
		}
		file2 << '.' << std::endl;
		for (const auto& task : project->getTasks())
		{
			file2 << task->getID() << ' ';
		}
		file2 << std::endl << '.' << std::endl;
	}
	file2 << '/' << std::endl;
		file1.close();
		file2.close();
}


void JiraSystem::unassignCurrentUser()
{
	currentUser = nullptr;
	std::cout << "User has been logged out" << std::endl;
}


void JiraSystem::addUser(const std::string& username, const std::string& password, const Role& role)
{
	auto p = std::make_unique<User>(username, password, role);
	std::ofstream file("Users.txt", std::ios::app);
	if (!file.is_open())
	{
		//exc
	}
	file << p->getId() << ' ' << username << ' ' << password << ' ' << roleToString(role) << std::endl;
	users.push_back(std::move(p));
	file.close();
}

void JiraSystem::removeUser(const std::string& username)
{
	for (size_t i = 0; i < users.size(); i++)
	{
		if (users[i]->getUsername() == username)
		{
			users.erase(users.begin() + i);
			removeUserFromFile(i);
			i--;
			std::cout << "ye";
		}
	}
}

bool JiraSystem::isNew() const
{
	std::ifstream file1("Users.txt");
	std::ifstream file3("Projects.txt");
	std::ifstream file4("Tasks.txt");
	if (!file1.is_open() || !file3.is_open() || !file4.is_open())
	{
		file1.close();
		file3.close();
		file4.close();
		return true;
	}
	file1.close();
	file3.close();
	file4.close();
	return false;
}

void JiraSystem::createNew()
{
	std::ofstream file1("Users.txt");
	std::ofstream file3("Projects.txt");
	std::ofstream file4("Tasks.txt");
	if (!file1.is_open() || !file3.is_open() || !file4.is_open())
	{
		//exc
		isRunning = false;
	}
	std::cout << "Create admin account\n";
	std::cout << "Username: \n";
	std::string adminName;
	std::cin >> adminName;
	std::cout << "Password: \n";
	std::string adminPassword;
	std::cin >> adminPassword;

	addUser(adminName, adminPassword, Role::Administrator);
	assignCurrentUser(users[0].get());
	file1.close();
	file3.close();
	file4.close();
}

void JiraSystem::loadUsers()
{
	std::ifstream file("Users.txt");
	if (!file.is_open())
	{
		//exc
	}
	while (true)
	{
		unsigned id = 0;
		std::string username;
		std::string password;
		std::string roleString;
		file >> id >> username >> password >> roleString;
		Role role = stringToRole(roleString);
		users.push_back(UserFactory::makeUser(username, password, role));
		if (file.eof())
		{
			break;
		}
	}
	file.close();
}

void JiraSystem::loadTasks()
{
	std::ifstream file("Tasks.txt");
	if (!file.is_open())
	{
		//exc
	}
	while (true)
	{
		unsigned id;
		std::string title;
		std::string desc;
		std::string taskTypeStr;
		std::string priorityStr;
		std::string taskStatusStr;
		unsigned day;
		unsigned month;
		unsigned year;
		unsigned points;
		unsigned grade;
		file >> id >> title >> desc >> taskTypeStr >> priorityStr >> taskStatusStr >> day >> month >> year >> points >> grade;
		TaskType type = stringToTaskType(taskTypeStr);
		Priority priority = stringToPriority(priorityStr);
		TaskStatus status = stringToTaskStatus(taskStatusStr);
		Date deadline(day, month, year);
		auto q = std::make_shared<Task>(id, title, desc, type, priority, status, deadline, points, grade);
		std::string input;
		file >> input;
		//while (input != ".")
		//{
		//	unsigned userId = fromStringToNum(input);
		//	User* user = findUserById(userId);
		//	q->addUser(*user);
		//	file >> input;
		//}
		//file >> input;
		//while (input != ".")
		//{
		//	unsigned taskId = fromStringToNum(input);
		//	Task* task = findTaskWithId(taskId);
		//	q->addTask(std::make_shared<Task>(*task));
		//	file >> input;
		//}
		tasks.push_back(q);
		file >> input;
		if (input == "/")
		{
			break;
		}
	}
	file.close();
}

void JiraSystem::loadProjects()
{
	std::ifstream file("Projects.txt");
	if (!file.is_open())
	{
		//exc
	}
	while (true)
	{
		std::string name;
		std::string desc;
		std::string projectStatusStr;
		unsigned day;
		unsigned month;
		unsigned year;
		file >> name >> desc >> day >> month >> year >> projectStatusStr;
		ProjectStatus status = stringToProjectStatus(projectStatusStr);
		Date startDate(day, month, year);
		auto q = std::make_unique<Project>(name, desc, startDate, status);
		std::string input;
		file >> input;
		while (input != ".")
		{
			unsigned userId = fromStringToNum(input);
			User* user = findUserById(userId);
			if (user)
			{
				q->addUser(*user);
			}
			file >> input;
		}
		file >> input;
		while (input != ".")
		{
			unsigned taskId = fromStringToNum(input);
			Task* task = findTaskWithId(taskId);
			if (task)
			{
				q->addTask(std::make_shared<Task>(*task));
			}
			file >> input;
		}
		projects.push_back(std::move(q));
		file >> input;

		if (input == "/")
		{
			break;
		}
	}
	file.close();
}

void JiraSystem::removeUserFromFile(unsigned index)
{
	std::ifstream inFile("Users.txt");
	std::vector<std::string> lines;
	std::string line;

	while (std::getline(inFile, line))
		lines.push_back(line);

	inFile.close();

	if (index >= lines.size())
		return;

	lines.erase(lines.begin() + index);

	std::ofstream outFile("Users.txt");

	for (const auto& line : lines)
		outFile << line << '\n';
}
