#ifndef FILESTORAGE_H
#define FILESTORAGE_H
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>
#include <sstream>
#include "Assignment.h"
#include "TaskManager.h"


class FileStorage
{
private:
  std::filesystem::path dataFolder = "dataFolder";
  std::filesystem::path dataFile = dataFolder / "dataFile.txt";

public:
  FileStorage();
  void saveAssignments(TaskManager &ob);
  void loadAssignments(TaskManager &ob);
};

#endif

