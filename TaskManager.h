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
  void addAssignmnet(std::string id,std::string title,bool completed,std::string subject,std::string deadline);
  void addAssignment();
  void listAssignments();
  void markAssignmentComplete();
  friend class FileStorage;
};
#endif