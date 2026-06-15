#pragma once

enum class ProjectStatus
{
	Active,
	Finished
};

inline std::string projectStatusToString(const ProjectStatus& projectStatus)
{
	switch (projectStatus)
	{
	case ProjectStatus::Active:
		return "Active";
	case ProjectStatus::Finished:
		return "Finished";
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
}