#pragma once
#include <string>
#include <vector>

class CommandSystem
{
	std::vector<std::string> parsedCommand;
public:
	void parseCommand(std::string command);
};