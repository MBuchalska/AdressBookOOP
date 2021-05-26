#include <iostream>
#include <vector>
#include "FileManager.h"
#include "UserManager.h"
#include "ContactData.h"
#include "auxiliary.h"
#ifndef CONTACTMANAGER_H
#define CONTACTMANAGER_H

using namespace std;

class ContactManager {
const int LOGGED_USER_ID;
ContactData contact;
vector<ContactData> contacts;
UserManager USER;
int NumberOfContacts;
FileManager file;
Auxiliary Text;

public:
ContactManager(string ContactFileName, int LoggedUserID)
:file (ContactFileName), LOGGED_USER_ID(LoggedUserID){
contacts=file.DownloadContactsFromFile(LOGGED_USER_ID, ContactFileName);
};

void AddNewContact(int OwnerID, int TotalNumberOfContacts, int LastContactID, string ContactFileName); // adds new contact
void PrintAllContactsOfLoggedUser();  // prints all contacts on screen
void ChangeContactData(string ContactFileName);              // changes data of a contact
int DeleteContact(int TotalNumberOfContacts, string ContactFileName);           //deletes a contact
void FindContactByFirstName();
void FindContactByLastName();
};


#endif // CONTACTMANAGER_H
