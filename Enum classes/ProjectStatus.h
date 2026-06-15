#pragma once

enum class ProjectStatus
{
	Active,
	Finished,
	Archived
};

inline std::string projectStatusToString(const ProjectStatus& projectStatus)
{
	switch (projectStatus)
	{
	case ProjectStatus::Active:
		return "Active";
	case ProjectStatus::Finished:
		return "Finished";
	case ProjectStatus::Archived:
		return "Archived";
	default:
		return "Unknown";
	}
}

inline ProjectStatus stringToProjectStatus(const std::string& str)
{
	if (str == "Active")
	{
		return ProjectStatus::Active;
	}
	else if (str == "Finished")
	{
		return ProjectStatus::Finished;
	}
	else if (str == "Archived")
	{
		return ProjectStatus::Archived;
	}
}