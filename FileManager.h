#ifndef FILEMANAGER_h
#define FILEMANAGER_h
#include <iostream>
#include <fstream>
#include <vector>
#include "UserData.h"
#include "ContactData.h"
#include "auxiliary.h"

using namespace std;

class FileManager{
const string USER_FILE_NAME;
fstream uzytkownicy, znajomi;
Auxiliary aux;
int LastContactID;

UserData AddUserDataToVector(string line);          //downloads single user to UserData format
ContactData AddContactsToVector(string line);       //downloads single contact do ContactDataFormat

public:
FileManager();
FileManager(string USERFILENAME)    //constructor with const UserFileName and ContactFilename
:USER_FILE_NAME(USERFILENAME) {};

void addUserToFile(string line);          //saves user in txt file
vector <UserData> DownloadUsersFromFile(); //adds users from file to vector
void ClearUserFile();                        //clears a file with Users
void addContactsToFile(string line, string ContactFileName);        // adds Contacts to txt file
vector <ContactData> DownloadContactsFromFile(int LoggedUserID, string ContactFileName); //downloads contacts from file
int HowManyContacts(string ContactFileName);                  //checks how many contacts are in the file overall
void ChangeContactInFile(ContactData TempContact, string ContactFileName);
int getLastContactID();
};

#endif
