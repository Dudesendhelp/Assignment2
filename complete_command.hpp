#pragma once
#include "icommand.hpp"
#include <CLI11.hpp>
#include "TaskManager.h"

class CompleteCommand : public ICommand
{
    private:
    TaskManager *taskmanager;
    void execute()
    {
        taskmanager->markAssignmentComplete(std::stoi(sid));
    }
public:
    CompleteCommand(TaskManager &taskManager)
    {
        this->taskmanager = &taskManager;
    }
    std::string sid;
    void setup(CLI::App &app) override
    {
        app.add_option("id", sid, "Enter the ID of the assignment to mark as complete")->required();
    
    
   
        app.callback([this]() {
            this->execute();
        });
    }
};