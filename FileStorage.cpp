#include "FileStorage.h"
#include <iostream>
using namespace std;
using namespace std::filesystem;


FileStorage::FileStorage()
  {
    if (!exists(dataFolder))
    {
      create_directory(dataFolder);
    }
  }

void FileStorage::saveAssignments(TaskManager &ob)
  {

    ofstream file(dataFile, ios::trunc);
    if (file.is_open())
    {
      for (auto i : ob.assignments)
      {
        file << i.getId() << "|" << i.getTitle() << "|" << i.isCompleted() << "|" << i.getSubject() << "|" << i.getDeadline() << endl;
      }
      file.close();
    }
    else
    {
      cout << "Error in opening file" << endl;
    }
  }

void FileStorage::loadAssignments(TaskManager &ob)
  {

    ifstream file(dataFile);
    string line = "";
    if (file.is_open())
    {
      while (getline(file, line))
      {
        stringstream ss(line);

        string id, title, subject, deadline;
        bool completed;
        string com;
        getline(ss, id, '|');
        getline(ss, title, '|');
        getline(ss, com, '|');
        getline(ss, subject, '|');
        getline(ss, deadline, '|');
        if (com == "1")
          completed = true;
        else
          completed = false;
        ob.addAssignmnet(id,title,completed,subject,deadline);
      }
      cout << "Completed reading the file" << endl;
      file.close();
    }
    else
    {
      cout << "Could not open the file" << endl;
    }
  }