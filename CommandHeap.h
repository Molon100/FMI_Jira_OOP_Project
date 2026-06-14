#pragma once
#include "Command.h"
#include <memory>

class CommandHeap
{
	std::vector<std::unique_ptr<Command>> commands;
public:
	Command* findCommandByName(const std::string name) const;
	CommandHeap(); 
};