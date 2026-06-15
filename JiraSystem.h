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
	std::vector<std::unique_ptr<Project>> projcets;
	std::vector<std::unique_ptr<Task>> tasks;
	bool isRunning = true;
	const User* currentUser;
	CommandSystem cs;
	void addUser(const std::string& username, const std::string& password, const Role& role);
	bool isNew() const;
	void createNew();
	void loadUsers();
public:
	const User* findUserByUsername(const std::string& username) const;
	const User* getCurrentUser() const;
	void unassignCurrentUser();
	void assignUser(const User* user);
	void run();
	void stopRunning();
};