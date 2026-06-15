#pragma once

enum class Priority
{
	Low,
	Medium,
	High,
	Critical
};

inline std::string priotityToString(const Priority& priority)
{
	switch (priority)
	{
	case Priority::Low:
		return "Low";
	case Priority::Medium:
		return "Medium";
	case Priority::High:
		return "High";
	case Priority::Critical:
		return "Critical";
	default:
		return "Unknown";
	}
}

inline Priority stringToPriority(const std::string& str)
{
	if (str == "Low")
	{
		return Priority::Low;
	}
	else if (str == "Medium")
	{
		return Priority::Medium;
	}
	else if (str == "High")
	{
		return Priority::High;
	}
	else if (str == "Critical")
	{
		return Priority::Critical;
	}
}