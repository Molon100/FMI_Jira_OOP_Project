#pragma once
#include <vector>
#include <memory>
#include "User.h"
#include "Project.h"
#include "Task.h"

class JiraSystem
{
	std::vector<std::unique_ptr<User>> users;
	std::vector<std::unique_ptr<Project>> projcets;
	std::vector<std::unique_ptr<Task>> tasks;

	void addUser(const std::string& username, const std::string& password, const Role& role);
public:
	bool isNew() const;
	void createNew();
};