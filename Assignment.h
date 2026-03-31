#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H
#include "Task.h"
#include <string>

class Assignment : public Task
{
private:
  std::string subject;
  std::string deadline;
public:
  void display() override;
  Assignment(int id, std::string title, bool completed, std::string subject, std::string deadline);
  std::string getSubject();
  std::string getDeadline();
};

#endif