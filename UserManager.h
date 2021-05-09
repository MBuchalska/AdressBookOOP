#include <iostream>
#include <vector>
#include "UserData.h"
#include "FileManager.h"
#ifndef USERMANAGER_h
#define USERMANAGER_h



using namespace std;

class UserManager {
    int numberOfUsers;
    int TempUserID;             //jeszcze nie u¿ywany, ale bêdzie przy logowaniu
    vector <UserData> users;    //operating vector with users
    UserData USER;              //for single user data
    FileManager file;           //file with users

public:
    void UserRegister();        // registration of new user
    void PrintAllUsers();       // shows all users on the screen
};



#endif
