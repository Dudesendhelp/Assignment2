#pragma once
#include "icommand.hpp"
#include "TaskManager.h"

class AddCommand : public ICommand
{
private:
    TaskManager *taskmanager;
    std::string title;
    bool completed=false;
    std::string subject="None";
    std::string deadline="None";

    void  execute()
    {
        taskmanager->addAssignment(-1, title, completed, subject, deadline);
    }
public:
    AddCommand(TaskManager &taskManager)
    {
        this->taskmanager = &taskManager;
    
    }

    void setup(CLI::App &app) override
    {
        
        app.add_option("title", title, "Title of the assignment");
        
        app.add_flag("--completed", completed, "Mark the assignment as completed");
        
        app.add_option("--subject", subject, "Subject of the assignment");
       
        app.add_option("--deadline", deadline, "Deadline of the assignment");
        app.callback([this]() { 
        this->execute(); 
    });
       
    }
};