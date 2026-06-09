#pragma once
#include <string>
#include <vector>
#include <memory>
#include "TaskType.h"
#include "Status.h"
#include "Priority.h"
#include "Comment.h"
#include "Date.h"
#include "User.h"

class Task
{
	static size_t numberOfTasks;
	unsigned id;
	std::string title;
	std::string description;
	TaskType type;
	Priority priority;
	Status status;
	std::unique_ptr<User> userInCharge;
	Date date;
	unsigned points;
	unsigned grade;
	std::vector<std::unique_ptr<Comment>> comments;
};