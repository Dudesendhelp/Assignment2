#include "Task.h"
#include <iostream>
#include <iomanip>
using namespace std;

Task::Task(string id, string title, bool completed)
{
    this->id = id;
    this->title = title;
    this->completed = completed;
}


void Task::display()
{
    cout << left << setw(10) << id 
         << " | " << setw(20) << title 
         << " | " << setw(12) << (completed ? "Completed" : "Pending");
}


string Task::getId()
{
    return id;
}


string Task::getTitle()
{
    return title;
}


void Task::markComplete()
{
    completed = true;
}


bool Task::isCompleted()
{
    return completed;
}


Task::~Task()
{

}