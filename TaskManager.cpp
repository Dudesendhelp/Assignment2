#include "TaskManager.h"
#include "FileStorage.h"
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

void TaskManager::addAssignmnet(std::string id,std::string title,bool completed,std::string subject,std::string deadline)
{
  assignments.push_back(Assignment(id, title, completed, subject, deadline));
}

void TaskManager::addAssignment(int a)
{
  if(a==-1)
  {
    
  string title;
      string id;
      bool completed;
      string subject;
      string deadline;
      cout<<"Please enter Id, Title of the Task, if the task is completed(enter 1 for true/enter 0 for false), subject of the task and deadline of the task as given order"<<endl;
      cin>>id;
      cin>>title;
      cin>>completed;
      cin>>subject;
      cin>>deadline;
  assignments.push_back(Assignment(id, title, completed, subject, deadline));

  
 cout<<"Do you want to save the assignment?(Press any key to save/Press 0 to cancel)"<<endl;
 char in;
 cin>>in;
 
 if(in!='0')
 {
      FileStorage f;
      f.saveAssignments(*this);
 }
}
else{
   FileStorage f;
      f.saveAssignments(*this);
}

}

void TaskManager::listAssignments()
{
  cout << left << setw(10) << "ID" 
       << " | " << setw(20) << "Title" 
       << " | " << setw(12) << "Status"
       << " | " << setw(15) << "Subject"
       << " | " << setw(15) << "Deadline" << endl;
  cout << string(85, '-') << endl;
  for (auto &i : assignments)
  {
    i.display();
  }
  cout<<"Load Assignments saved in memory?(Press any key to load/Press 0 to not load)"<<endl;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  char in;
  cin>>in;
  if(in!='0')
  {  cin.ignore(numeric_limits<streamsize>::max(), '\n');
    FileStorage f;
    f.loadAssignments(*this);
  
   for (auto &i : assignments)
  {
    i.display();
  }
}

}

void TaskManager::markAssignmentComplete()
{
  string id;
  cout<<"Enter the task id"<<endl;
  cin>>id;
  bool found = false;
  for (auto &i : assignments)
  {
    if (i.getId() == id)
    {
      i.markComplete();
      found = true;
    }
  }
  if(found)
  {
    cout << "Task with id " << id << " marked as complete." << endl;
    FileStorage f;
    f.saveAssignments(*this);
  }
  else
  {
    cout << "No task found with id " << id << "." << endl;
  }
}