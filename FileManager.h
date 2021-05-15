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

UserData AddUserDataToVector(string line);          //downloads single user to UserData format

public:
FileManager();
FileManager(string USERFILENAME):UserFileName(USERFILENAME){};          //constructor with const UserFileName
void addUserToFile(string line);          //saves user in txt file
vector <UserData> DownloadUsersFromFile(); //adds users from file to vector
void ClearUserFile();                        //clears a file with Users
};

#endif
