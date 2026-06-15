#pragma once
#include <string>
#include <vector>
#include <memory>
#include "TaskType.h"
#include "TaskStatus.h"
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
	TaskStatus status;
	std::weak_ptr<User> userInCharge;
	Date deadline;
	unsigned points;
	unsigned grade;
	std::vector<std::unique_ptr<Comment>> comments;
	std::vector<std::string> historyOfChanges;
public:

	Task(unsigned id, const std::string& title, const std::string& description, const TaskType& type, const Priority& priority);
};