#include "TaskManager.h"
#include "FileStorage.h"
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

void TaskManager::addAssignment(int id,std::string title,bool completed,std::string subject,std::string deadline)
{
    FileStorage f;
    f.loadAssignments(*this);
  if(id==-1 && !assignments.empty())
  {
    id=assignments.back().getId()+1;
  }
  else if(id==-1)
  {
    id=1;
  }
  assignments.push_back(Assignment(id, title, completed, subject, deadline));
   
      f.saveAssignments(*this);

}

void TaskManager::addAssignment(int a)
{
 if(a<1)
 {
   {
    FileStorage f;
    f.loadAssignments(*this);
  }
 }
  int id=assignments.back().getId()+1;
  string title;
    
      bool completed;
      string subject;
      string deadline;
      cout<<"Please enter Title of the Task, if the task is completed(enter 1 for true/enter 0 for false), subject of the task and deadline of the task as given order"<<endl;
     
      cin>>title;
      cin>>completed;
      cin>>subject;
      cin>>deadline;
  assignments.push_back(Assignment(id, title, completed, subject, deadline));

  

 

      FileStorage f;
      f.saveAssignments(*this);

}

void TaskManager::listAssignments(int a)
{
  cout << left << setw(10) << "ID" 
       << " | " << setw(20) << "Title" 
       << " | " << setw(12) << "Status"
       << " | " << setw(15) << "Subject"
       << " | " << setw(15) << "Deadline" << endl;
  if(a==1)
  {
    FileStorage f;
    f.loadAssignments(*this);
  }
   for (auto &i : assignments)
  {
    i.display();
  }


}

void TaskManager::deleteAssignment()
{
  FileStorage f;
  f.loadAssignments(*this);
  cout<<"Enter the task id to be deleted"<<endl;
  int id;
  cin>>id;
  bool found = false;
  for (auto it = assignments.begin(); it != assignments.end(); ++it)
  {
    if (it->getId() == id)
    {
      assignments.erase(it);
      cout << "Task with id " << id << " deleted." << endl;
      f.saveAssignments(*this);
      found = true;
      break;
    }
  }
  if(!found)
  {
    cout << "No task found with id " << id << "." << endl;
  }
}

void TaskManager::deleteAssignment(int id)
{
  FileStorage f;
  f.loadAssignments(*this);
  bool found = false;
  for (auto it = assignments.begin(); it != assignments.end(); ++it)
  {
    if (it->getId() == id)
    {
      assignments.erase(it);
      cout << "Task with id " << id << " deleted." << endl;
      f.saveAssignments(*this);
      found = true;
      break;
    }
  }
  if(!found)
  {
    cout << "No task found with id " << id << "." << endl;
  }
}



void TaskManager::markAssignmentComplete()
{
  FileStorage f;
  f.loadAssignments(*this);
  int id;
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
    f.saveAssignments(*this);
  }
  else
  {
    cout << "No task found with id " << id << "." << endl;
  }
}

void TaskManager::markAssignmentComplete(int id)
{
  FileStorage f;
  f.loadAssignments(*this);
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
    f.saveAssignments(*this);
  }
  else
  {
    cout << "No task found with id " << id << "." << endl;
  }
}