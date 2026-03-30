#ifndef TASK_H
#define TASK_H
#include <iostream>
#include <string>


class Task
{
protected:
  std::string id;
  std::string title;
  bool completed;
public:
  Task(std::string id, std::string title, bool completed);
  virtual void display();
  std::string getId();
  std::string getTitle();
  void markComplete();
  bool isCompleted();
  virtual ~Task();
};

#endif