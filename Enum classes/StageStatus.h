#pragma once

enum class StageStatus
{
	Planned,
	Active,
	Finished
};

inline std::string stageStatusToString(const StageStatus& stageStatus)
{
	switch (stageStatus)
	{
	case StageStatus::Planned:
		return "Planned";
	case StageStatus::Active:
		return "Active";
	case StageStatus::Finished:
		return "Finished";
	default:
		return "Unknown";
	}
}

inline StageStatus stringToStageStatus(const std::string& str)
{
	if (str == "Planned")
	{
		return StageStatus::Planned;
	}
	else if (str == "Active")
	{
		return StageStatus::Active;
	}
	else if (str == "Finished")
	{
		return StageStatus::Finished;
	}
}