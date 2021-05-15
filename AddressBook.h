#include <iostream>
#include <vector>
#include "UserManager.h"
#ifndef ADDRESSBOOK_h
#define ADDRESSBOOK_h

using namespace std;

class AddressBook {
UserManager user;

public:
void UserRegister();        // registration of new user
void PrintAllUsers();       // shows all users on the screen
void LoginUser();           // logging in the user
void ChangeUserPassword();  // changes logged user's password

AddressBook(string UserFileName)    // constructor that downloads users from the file
:user(UserFileName)
{
user.DownloadUsersFromFile();
}

};


#endif // ADDRESSBOOK_h
