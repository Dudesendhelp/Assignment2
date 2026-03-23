#include "TaskManager.h"
#include <string>
#include <vector>
using namespace std;

void TaskManager::addAssignment(string id, string title, bool completed, string subject, string deadline)
{
  assignments.push_back(Assignment(id, title, completed, subject, deadline));
}

void TaskManager::listAssignments()
{
  for (auto &i : assignments)
  {
    i.display();
  }
}

void TaskManager::markAssignmentComplete(string id)
{
  for (auto &i : assignments)
  {
    if (i.getId() == id)
    {
      i.markComplete();
    }
  }
}