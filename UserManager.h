#include <iostream>
#include <vector>
#include "UserData.h"
#include "FileManager.h"
#include "auxiliary.h"
#ifndef USERMANAGER_h
#define USERMANAGER_h

using namespace std;

class UserManager {
    int numberOfUsers;
    int LoggedUserID;            //ID of the user that is logged in
    vector <UserData> users;    //operating vector with users
    UserData USER;              //for single user data
    FileManager file;           //file with users
    Auxiliary DataInLine;

public:
    UserManager(string UserFileName, string ContactFileName)//refers to const user and contact filename
    :file(UserFileName, ContactFileName) {};
    UserManager();              // constructor with initial declaration of logged user ID
    ~UserManager();             // destructor; logging user out
    void UserRegister();        // registration of new user
    void PrintAllUsers();       // shows all users on the screen
    void DownloadUsersFromFile(); //downloads users from file to vector
    int LoginUser();            // logging the user in
    void ChangeUserPassword();  // changes logged user's password
};



#endif
