#include <iostream>
#include <fstream>
#include <vector>
#include "UserData.h"
#ifndef FILEMANAGER_h
#define FILEMANAGER_h


using namespace std;

class FileManager{
const string UserFileName;
const string ContactFileName;
fstream uzytkownicy;

UserData AddUserDataToVector(string line);          //downloads single user to UserData format

public:
FileManager();
FileManager(string USERFILENAME, string CONTACTFILENAME)    //constructor with const UserFileName and ContactFilename
:UserFileName(USERFILENAME),ContactFileName(CONTACTFILENAME) {};

void addUserToFile(string line);          //saves user in txt file
vector <UserData> DownloadUsersFromFile(); //adds users from file to vector
void ClearUserFile();                        //clears a file with Users
};

#endif
