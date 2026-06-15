#pragma once

enum class TaskStatus
{
	ToDo,
	InProgress,
	InReview,
	Done
};

inline std::string taskStatusToString(const TaskStatus& taskStatus)
{
	switch (taskStatus)
	{
	case TaskStatus::ToDo:
		return "ToDo";
	case TaskStatus::InProgress:
		return "InProgress";
	case TaskStatus::InReview:
		return "InReview";
	case TaskStatus::Done:
		return "Done";
	default:
		return "Unknown";
	}
}

inline TaskStatus stringToTaskStatus(const std::string& str)
{
	if (str == "ToDo")
	{
		return TaskStatus::ToDo;
	}
	else if (str == "InProgress")
	{
		return TaskStatus::InProgress;
	}
	else if (str == "InReview")
	{
		return TaskStatus::InReview;
	}
	else if (str == "Done")
	{
		return TaskStatus::Done;
	}
}