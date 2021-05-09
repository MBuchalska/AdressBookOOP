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
};

#endif // ADDRESSBOOK_h
