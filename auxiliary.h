#ifndef AUXILIARY_h
#define AUXILIARY_h
#include <iostream>
#include <string>
#include "UserData.h"
#include "ContactData.h"

using namespace std;

class Auxiliary{
    UserData USER;
    ContactData contact;

public:
    string UserDataInOneLine(UserData USER);
    string ContactDataInOneLine(ContactData contact, int OwnerID);
};

#endif // AUXILIARY_h


