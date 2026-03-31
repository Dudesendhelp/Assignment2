#pragma once
#include "icommand.hpp"
#include "TaskManager.h"
#include <CLI11.hpp>

class ListCommand : public ICommand
{

private:
    TaskManager *taskmanager;
    void execute()
    {
        taskmanager->listAssignments(1);
    }
public:
    ListCommand(TaskManager &taskManager)
    {
        this->taskmanager = &taskManager;
    }

     void setup(CLI::App &app) override
     {
        app.callback([this]() { 
        this->execute();});
     }
};