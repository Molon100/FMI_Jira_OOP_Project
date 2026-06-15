#include "JiraSystem.h"
#include <iostream>
#include <fstream>
#include <string>

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
	return nullptr;
}

Task* JiraSystem::findTaskWithId(unsigned id) const
{
	for (const auto& project : projects)
	{
		if (auto q = findTaskWithId(id))
		{
			return q;
		}
	}
	return nullptr;
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
	return nullptr;
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
	auto p = std::make_unique<Project>(name);
	std::ofstream file("Projects.txt", std::ios::app);
	if (!file.is_open())
	{
		//exc
	}
	file << name << " Active";
	projects.push_back(std::move(p));
	file.close();
}

void JiraSystem::save() const
{
	std::ofstream file("Projects.txt");
		if (!file.is_open())
		{
			//exc
		}
	for (const auto& project : projects)
	{
		file << *project;
	}
		file.close();
}


void JiraSystem::unassignCurrentUser()
{
	currentUser = nullptr;
	std::cout << "unassigned";
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
	std::ifstream file2("Projects.txt");
	std::ifstream file3("Tasks.txt");
	if (!file1.is_open() || !file2.is_open() || !file3.is_open())
	{
		file1.close();
		file2.close();
		file3.close();
		return true;
	}
	file1.close();
	file2.close();
	file3.close();
	return false;
}

void JiraSystem::createNew()
{
	std::ofstream file1("Users.txt");
	std::ofstream file2("Projects.txt");
	std::ofstream file3("Tasks.txt");
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
	file2.close();
	file3.close();
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
		std::string projectStatusStr;
		file >> name >> projectStatusStr;
		ProjectStatus status = stringToProjectStatus(projectStatusStr);
		projects.push_back(std::make_unique<Project>(name, status));
		if (file.eof())
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
