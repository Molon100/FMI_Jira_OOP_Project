#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Stage.h"
#include "User.h"
#include "Task.h"
#include "ProjectStatus.h"

class Project
{
	std::string name;
	std::string description;
	Date startDate;
	std::vector<std::shared_ptr<User>> users;
	std::vector<std::unique_ptr<Task>> tasks;
	std::vector<std::unique_ptr<Stage>> stages;
	ProjectStatus status;
public:

	Project(const std::string& name, const std::string& description);
	Project(const std::string& name);
};