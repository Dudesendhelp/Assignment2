#ifndef TASKMANAGER_H
#define TASKMANAGER_H
#include "Assignment.h"
#include <vector>
#include <string>

class TaskManager
{
private:
  std::vector<Assignment> assignments;
public:
  void addAssignment(int id,std::string title,bool completed,std::string subject,std::string deadline);
  void addAssignment(int a);
  void deleteAssignment();
  void deleteAssignment(int id);
  void listAssignments(int a);
  void markAssignmentComplete();
  void markAssignmentComplete(int id);
  friend class FileStorage;
};
#endif