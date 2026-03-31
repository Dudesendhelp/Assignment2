#pragma once
#include "icommand.hpp"
#include "TaskManager.h"

class DeleteCommand : public ICommand
{
private:
    TaskManager *taskmanager;
    void execute()
    {
        taskmanager->deleteAssignment(std::stoi(sid));
    }
public:
    DeleteCommand(TaskManager &taskManager)
    {
        this->taskmanager = &taskManager;
    }
    std::string sid;
    void setup(CLI::App &app) override
    {
        app.add_option("id", sid, "Enter the ID of the assignment to delete")->required();
        app.callback([this]() {
            this->execute();
        });
    }
};
