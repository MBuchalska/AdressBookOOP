#include <iostream>
#include <vector>
#include "UserManager.h"
#include "ContactManager.h"
#ifndef ADDRESSBOOK_h
#define ADDRESSBOOK_h

using namespace std;

class AddressBook {
UserManager user;
ContactManager contact;

public:
void UserRegister();        // registration of new user
void PrintAllUsers();       // shows all users on the screen
void LoginUser();           // logging in the user
void ChangeUserPassword();  // changes logged user's password
void LogoutUser();
void AddNewContact();       // adds new contact for logged user


AddressBook(string UserFileName, string ContactFileName)    // constructor that downloads users from the file
:user(UserFileName, ContactFileName)
{
user.DownloadUsersFromFile();
user.setLoggedUserID(0);
}

};


#endif // ADDRESSBOOK_h
