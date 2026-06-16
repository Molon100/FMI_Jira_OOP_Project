#pragma once

enum class TaskType
{
	Bug,
	Feature,
	Task,
	Improvement
};

inline std::string taskTypeToString(const TaskType& taskType)
{
	switch (taskType)
	{
	case TaskType::Bug:
		return "Bug";
	case TaskType::Feature:
		return "Feature";
	case TaskType::Task:
		return "Task";
	case TaskType::Improvement:
		return "Improvement";
	default:
		return "Unknown";
	}
}

inline TaskType stringToTaskType(const std::string& str)
{
	if (str == "Bug")
	{
		return TaskType::Bug;
	}
	else if (str == "Feature")
	{
		return TaskType::Feature;
	}
	else if (str == "Task")
	{
		return TaskType::Task;
	}
	else if (str == "Improvement")
	{
		return TaskType::Improvement;
	}
}