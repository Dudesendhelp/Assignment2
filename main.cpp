#include "Assignment.h"
#include "FileStorage.h"
#include "Task.h"
#include "TaskManager.h"
#include <iostream>
#include <limits>
using namespace std;

int main()
{
   TaskManager taskmanager;
   while(true)
   {
    int x;
    cout << "\n============================================\n";
    cout << "            TASK MANAGER MENU               \n";
    cout << "============================================\n";
    cout << " 1. List Assignments\n";
    cout << " 2. Add New Assignment\n";
    cout << " 3. Mark Assignment Complete\n";
    cout << " 4. Exit\n";
    cout << "============================================\n";
    cout << "Enter your choice: ";
    
    if(!(cin>>x))
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "\n[!] Invalid input. Please enter a number between 1 and 4.\n";
      continue;
    }
    
    cout << "\n--------------------------------------------\n";
    
    switch(x)
    {
      case 1:
        taskmanager.listAssignments();
        break;
      case 2:
        taskmanager.addAssignment();
        break;
      case 3:
        taskmanager.markAssignmentComplete();
        break;
      case 4:
        cout << "Program terminated. Goodbye!\n";
        return 0;
      default:
        cout << "[!] Wrong choice, please enter a valid option (1-4).\n";
    }
   }
}