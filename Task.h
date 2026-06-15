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
	const User* userInCharge;
	Date deadline;
	unsigned points;
	unsigned grade;
	std::vector<std::unique_ptr<Comment>> comments;
	std::vector<std::string> historyOfChanges;
public:

	Task(const TaskType& type, const Priority& priority);
	void assignUserInCharge(const User* user);
	void setTitle(const std::string& title);
	void setDesc(const std::string& desc);
	unsigned getID() const;
	friend std::ostream& operator<<(std::ostream& os, const Task& task);

};