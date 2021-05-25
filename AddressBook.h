#include <iostream>
#include <vector>
#include "UserManager.h"
#include "ContactManager.h"
#include "FileManager.h"
#ifndef ADDRESSBOOK_h
#define ADDRESSBOOK_h

using namespace std;

class AddressBook {
UserManager user;
ContactManager *contact;
const string CONTACT_FILE_NAME;
vector <ContactData> contacts;
FileManager file;
int NumberOfContacts;
int LastContactID;

public:
void UserRegister();        // registration of new user
void PrintAllUsers();       // shows all users on the screen; temporary
void LoginUser();           // logging in the user
void ChangeUserPassword();  // changes logged user's password
void LogoutUser();
void AddNewContact();       // adds new contact for logged user, and downloads contacts
void PrintAllContactsOfLoggedUser(); // shows all contacts of logged user
void ChangeContactData();           // changes contact data


AddressBook(string UserFileName, string ContactFileName)    // constructor that downloads users from the file
:user(UserFileName), CONTACT_FILE_NAME(ContactFileName){
contact = NULL;
user.setLoggedUserID(0);
NumberOfContacts=file.HowManyContacts(CONTACT_FILE_NAME);
LastContactID=file.getLastContactID();
}

~AddressBook () {
delete contact;
contact = NULL;
}

};


#endif // ADDRESSBOOK_h
