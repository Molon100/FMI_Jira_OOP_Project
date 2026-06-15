#pragma once
#include <string>
#include <vector>
#include <memory>
#include "StageStatus.h"
#include "Date.h"
#include "Task.h"

class Stage
{
	std::string name;
	Date startDate;
	Date endDate;
	std::vector<std::unique_ptr<Task>> tasks;
	StageStatus status;
public:

	Stage(const std::string& name);
};