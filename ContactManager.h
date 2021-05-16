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
ContactData contact;
vector<ContactData> contacts;
int TempUserID;
UserManager USER;
int NumberOfContacts;
FileManager file;
Auxiliary Text;

public:
void AddNewContact(int OwnerID);
ContactManager();

};


#endif // CONTACTMANAGER_H
