#include "icommand.hpp"
#include <CLI11.hpp>
#include "TaskManager.h"
#include "list_command.hpp"
#include "add_command.hpp"
#include "delete_command.hpp"
#include "complete_command.hpp"

int main(int argc, char *argv[])
{
    CLI::App app{"Task Manager CLI"};
    TaskManager taskManager;
    auto list=app.add_subcommand("list", "List all assignments");
    auto add=app.add_subcommand("add", "Add a new assignment");
    auto delete_=app.add_subcommand("delete", "Delete an assignment");
    auto complete=app.add_subcommand("complete", "Mark an assignment as complete");


    ListCommand listCommand(taskManager);
    AddCommand addCommand(taskManager);
    DeleteCommand deleteCommand(taskManager);
    CompleteCommand completeCommand(taskManager);    


    listCommand.setup(*list);  
    addCommand.setup(*add);    
    deleteCommand.setup(*delete_);
    completeCommand.setup(*complete);


    CLI11_PARSE(app, argc, argv);


}