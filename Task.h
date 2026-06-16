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
	void copyFrom(const Task& other);
public:

	Task(unsigned id, const std::string& title, const std::string& desc,const TaskType& type, const Priority& priority, const TaskStatus& status, const Date& deadline, unsigned points, unsigned grade);
	Task(const TaskType& type, const Priority& priority);
	Task(const Task& other);
	Task& operator=(const Task& other);

	void assignUserInCharge(const User* user);
	void setTitle(const std::string& title, const std::string& authorName);
	void setDesc(const std::string& desc, const std::string& authorName);
	void changeStatus(TaskStatus newStatus, const std::string& authorName);

	unsigned getID() const;
	const std::string& getTitle() const;
	const std::string& getDesc() const;
	const TaskType& getType() const;
	const Priority& getPriority() const;
	const TaskStatus& getStatus() const;
	const std::weak_ptr<User>& getUserInCharge() const;
	const Date& getDate() const;
	unsigned getPoints() const;
	unsigned getGrade() const;
	const std::vector<std::unique_ptr<Comment>>& getComments() const;
	const std::vector<std::string>& getChanges() const;


	friend std::ostream& operator<<(std::ostream& os, const Task& task);

};