#pragma once
#include <vector>
#include <memory>
#include "User.h"
#include "Project.h"
#include "Task.h"
#include "CommandSystem.h"
#include "UserFactory.h"

class JiraSystem
{
	std::vector<std::unique_ptr<User>> users;
	std::vector<std::unique_ptr<Project>> projects;
	std::vector<std::shared_ptr<Task>> tasks;
	bool isRunning = true;
	const User* currentUser;
	CommandSystem cs;
	bool isNew() const;
	void createNew();
	void loadUsers();
	void removeUserFromFile(unsigned index);
public:
	const User* findUserByUsername(const std::string& username) const;
	const User* getCurrentUser() const;
	void unassignCurrentUser();
	void addUser(const std::string& username, const std::string& password, const Role& role);
	void removeUser(const std::string& username);
	void assignCurrentUser(const User* user);

	void addProject(const std::string& name);

	void run();
	void stopRunning();
};