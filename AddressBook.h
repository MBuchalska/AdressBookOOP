#include <iostream>
#include <vector>
#include "UserData.h"

using namespace std;

class AddressBook {
int numberOfUsers;
int TempUserID;

vector <UserData> users;  //operating vector
UserData USER;          // for single user data

public:
void UserRegister();     // registration

};
