#include <iostream>
#include <fstream>
#include <vector>
#include "UserData.h"
#ifndef FILEMANAGER_h
#define FILEMANAGER_h


using namespace std;

class FileManager{
const string UserFileName;
fstream uzytkownicy;

UserData AddUserDataToVector(string line);

public:
FileManager();
FileManager(string USERFILENAME):UserFileName(USERFILENAME){};          //constructor with const UserFileName
void addUserToFile(string line);          //saves user in txt file
vector <UserData> DownloadUsersFromFile(); //adds users from file to vector
};

#endif
