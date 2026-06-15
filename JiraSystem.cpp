#include "JiraSystem.h"
#include <iostream>
#include <fstream>
#include <string>

void JiraSystem::run()
{
	if (isNew())
	{
		createNew();
	}
	else
	{
		loadUsers();
	}
	while (isRunning)
	{
		cs.action(*this);
	}
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

void JiraSystem::assignUser(const User* user)
{
	currentUser = user;
}

void JiraSystem::unassignCurrentUser()
{
	currentUser = nullptr;
	std::cout << "unassigned";
}

void JiraSystem::addUser(const std::string& username, const std::string& password, const Role& role)
{
	auto p = std::make_unique<User>(username, password, Role::Administrator);
	std::ofstream file("Users.txt");
	if (!file.is_open())
	{
		//exc
	}
	file << p->getId() << ' ' << username << ' ' << password << ' ' << roleToString(role);
	users.push_back(std::move(p));
	file.close();
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
