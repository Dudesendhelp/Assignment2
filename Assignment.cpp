#include "Assignment.h"
#include "Task.h"
#include <string>
#include <iostream>
using namespace std;

Assignment ::Assignment(std::string id, std::string title, bool completed, std::string subject, std::string deadline) : Task(id, title, completed)
{

  this->subject = subject;
  this->deadline = deadline;
}

void Assignment::display() 
  {
    cout << "The subject is " << this->subject << " and the deadline is " << this->deadline << endl;
  }

std::string Assignment ::getSubject()
{
  return subject;
}

std::string Assignment::getDeadline()
{
  return deadline;
}