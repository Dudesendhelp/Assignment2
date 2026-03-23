#include "Task.h"
#include <iostream>
using namespace std;

Task::Task(string id, string title, bool completed)
{
    this->id = id;
    this->title = title;
    this->completed = completed;
}


void Task::display()
{
    cout << "ID: " << id << endl;
    cout << "Title: " << title << endl;
    cout << "Status: " << (completed ? "Completed" : "Pending") << endl;
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