#include "JiraSystem.h"
#include <iostream>
#include <fstream>

bool JiraSystem::isNew() const
{
	std::ifstream file1("Users.txt");
	std::ifstream file2("Projects.txt");
	std::ifstream file3("Tasks.txt");
	if (!file1.is_open() || !file2.is_open() || !file3.is_open())
	{
		file1.close();
		file2.close();
		file3.close();
		return true;
	}
	file1.close();
	file2.close();
	file3.close();
	return false;
}

void JiraSystem::createNew() const
{
	std::ofstream file1("Users.txt");
	std::ofstream file2("Projects.txt");
	std::ofstream file3("Tasks.txt");
	file1.close();
	file2.close();
	file3.close();
}
