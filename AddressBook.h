#include <iostream>
#include <vector>
#include "UserData.h"

using namespace std;

class AddressBook {
int numberOfUsers;
int TempUserID;
string UserFileName;

vector <UserData> users;    //operating vector with users
UserData USER;              // for single user data

public:
AddressBook();              // constructor with user file name
void UserRegister();        // registration of new user
void PrintAllUsers();       // shows all users on the screen
};
