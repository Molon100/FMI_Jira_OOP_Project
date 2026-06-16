#include "Task.h"
#include <stdexcept>

size_t Task::numberOfTasks = 0;

void Task::copyFrom(const Task& other)
{
	id = other.id;
	title = other.title;
	description = other.description;
	type = other.type;
	priority = other.priority;
	status = other.status;
	userInCharge = other.userInCharge;
	deadline = other.deadline;
	points = other.points;
	grade = other.grade;
	historyOfChanges = other.historyOfChanges;

	comments.clear();
	comments.reserve(other.comments.size());

	for (const auto& comment : other.comments)
	{
		comments.push_back(std::make_unique<Comment>(*comment));
	}
}

Task::Task(unsigned id, const std::string& title, const std::string& desc, const TaskType& type, const Priority& priority, const TaskStatus& status, const Date& deadline, unsigned points, unsigned grade)
	: id(id), title(title), description(desc), type(type), priority(priority), status(status), deadline(deadline), points(points), grade(grade)
{
}

Task::Task(const TaskType& type, const Priority& priority)
	: title(""), description(""), type(type), priority(priority), status(TaskStatus::ToDo),
	deadline(0,0,0),  points(0), grade(0)
{
	numberOfTasks++;
	id = numberOfTasks;

}

Task::Task(const Task& other)
{
	copyFrom(other);
}

Task& Task::operator=(const Task& other)
{
	if (this != &other)
	{
		copyFrom(other);
	}
	return *this;
}

void Task::assignUserInCharge(const User* user)
{
	//userInCharge = std::make_shared<User>(user);
}

void Task::setTitle(const std::string& title, const std::string& authorName)
{
	this->title = title;
	std::string change = "Title changed by author: " + authorName;
	historyOfChanges.push_back(change);
}

void Task::setDesc(const std::string& desc, const std::string& authorName)
{
	this->description = desc;
	std::string change = "Description changed by author: " + authorName;
	historyOfChanges.push_back(change);
}

void Task::changeGrade(unsigned grade)
{
	if (grade < 2 || grade > 6)
	{
		throw std::invalid_argument("Invalid grade");
	}
	this->grade = grade;
	std::cout << "Task has been graded" << std::endl;
}

void Task::changeStatus(TaskStatus newStatus, const std::string& authorName)
{
	status = newStatus;
	std::string change = "Task status changed by author: " + authorName;
	historyOfChanges.push_back(change);
	std::cout << "Status changed" << std::endl;
}

void Task::approve()
{
	status = TaskStatus::InReview;
	std::cout << "Task approved, awaiting review" << std::endl;
}

void Task::review()
{
	status = TaskStatus::Done;
	std::cout << "Task reviewed" << std::endl;
}

void Task::addComment(std::unique_ptr<Comment> comment)
{
	comments.push_back(std::move(comment));
}

unsigned Task::getID() const
{
	return id;
}

const std::string& Task::getTitle() const
{
	return title;
}

const std::string& Task::getDesc() const
{
	return description;
}

const TaskType& Task::getType() const
{
	return type;
}

const Priority& Task::getPriority() const
{
	return priority;
}

const TaskStatus& Task::getStatus() const
{
	return status;
}

const std::weak_ptr<User>& Task::getUserInCharge() const
{
	return userInCharge;
}

const Date& Task::getDate() const
{
	return deadline;
}

unsigned Task::getPoints() const
{
	return points;
}

unsigned Task::getGrade() const
{
	return grade;
}

const std::vector<std::unique_ptr<Comment>>& Task::getComments() const
{
	return comments;
}

const std::vector<std::string>& Task::getChanges() const
{
	return historyOfChanges;
}

std::ostream& operator<<(std::ostream& os, const Task& task)
{
	os << task.id << ' ' << task.title << ' ' << task.description << ' ' << taskTypeToString(task.type) << ' '
		<< priotityToString(task.priority) << ' ' << taskStatusToString(task.status) << ' ' 
		<< task.deadline << ' ' << task.points << ' ' << task.grade << std::endl;
	for (const auto& comment : task.comments)
	{
		os << comment << std::endl;
	}
	for (const auto& change : task.historyOfChanges)
	{
		os << change << std::endl;
	}
	return os;
}
