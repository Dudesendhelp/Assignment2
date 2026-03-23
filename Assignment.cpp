#include "Assignment.h"
#include "Task.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

Assignment ::Assignment(std::string id, std::string title, bool completed, std::string subject, std::string deadline) : Task(id, title, completed)
{

  this->subject = subject;
  this->deadline = deadline;
}

void Assignment::display() 
{
    Task::display();
    cout << " | " << left << setw(15) << subject 
         << " | " << left << setw(15) << deadline << endl;
}

std::string Assignment ::getSubject()
{
  return subject;
}

std::string Assignment::getDeadline()
{
  return deadline;
}