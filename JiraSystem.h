#pragma once
#include <vector>
#include "User.h"
#include "Project.h"
#include "Task.h"

class JiraSystem
{
	std::vector<User> users;
	std::vector<Project> projcets;
	std::vector<Task> tasks;
public:
	bool isNew() const;
	void createNew() const;
};