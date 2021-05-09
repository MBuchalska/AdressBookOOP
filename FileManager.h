#include <iostream>
#include <fstream>
#ifndef FILEMANAGER_h
#define FILEMANAGER_h


using namespace std;

class FileManager{
string UserFileName;

public:
FileManager();                             //constructor with UserFileName
void addUserToFile(string line);          //saves user in txt file
};

#endif
