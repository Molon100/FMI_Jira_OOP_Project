#include "Project.h"

Project::Project(const std::string& name, const std::string& description) : 
	name(name), description(description), startDate(1,1,2026), status(ProjectStatus::Active)
{
}

Project::Project(const std::string& name) 
	: name(name), description(""), startDate(1, 1, 2026), status(ProjectStatus::Active)
{
}
