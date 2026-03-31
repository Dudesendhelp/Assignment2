#ifndef TASK_H
#define TASK_H
#include <iostream>
#include <string>


class Task
{
protected:
  int id;
  std::string title;
  bool completed;
public:
  Task(int id, std::string title, bool completed);
  virtual void display();
  int getId();
  std::string getTitle();
  void markComplete();
  bool isCompleted();
  virtual ~Task();
};

#endif