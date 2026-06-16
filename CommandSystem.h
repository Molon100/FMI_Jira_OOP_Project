#pragma once
#include <string>
#include <vector>
#include "CommandHeap.h"

class JiraSystem;

class CommandSystem
{
	std::vector<std::string> parsedCommand;
	CommandHeap commandHeap;
	void parseCommand(const std::string& command);
	void executeCommand(const std::string&, JiraSystem& system) const;
public:
	void action(JiraSystem& system);
};