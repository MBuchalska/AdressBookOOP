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

};

#endif // AUXILIARY_h


