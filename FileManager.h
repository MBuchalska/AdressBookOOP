#ifndef FILEMANAGER_h
#define FILEMANAGER_h
#include <iostream>
#include <fstream>
#include <vector>
#include "UserData.h"
#include "ContactData.h"

using namespace std;

class FileManager{
const string UserFileName;
const string ContactFileName;
fstream uzytkownicy, znajomi;

UserData AddUserDataToVector(string line);          //downloads single user to UserData format
ContactData AddContactsToVector(string line);       //downloads single contact do ContactDataFormat

public:
FileManager();
FileManager(string USERFILENAME, string CONTACTFILENAME)    //constructor with const UserFileName and ContactFilename
:UserFileName(USERFILENAME),ContactFileName(CONTACTFILENAME) {};

void addUserToFile(string line);          //saves user in txt file
vector <UserData> DownloadUsersFromFile(); //adds users from file to vector
void ClearUserFile();                        //clears a file with Users
void addContactsToFile(string line);        // adds Contacts to txt file
vector <ContactData> DownloadContactsFromFile(int LoggedUserID); //downloads contacts from file
int HowManyContacts();                  //checks how many contacts are in the file overall
};

#endif
