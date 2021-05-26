#include <iostream>
#include <vector>
#include "UserData.h"
#include "FileManager.h"
#include "auxiliary.h"
#include "ContactData.h"
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
    UserManager(string UserFileName)//refers to const user and contact filename
        :file(UserFileName) {
        users=file.DownloadUsersFromFile();                 //downloads users from file to vector
    };
    UserManager();              // constructor with initial declaration of logged user ID
    ~UserManager();             // destructor; logging user out

    void UserRegister();        // registration of new user
    void PrintAllUsers();       // shows all users on the screen
    int LoginUser();            // logging the user in
    void ChangeUserPassword();  // changes logged user's password
    void setLoggedUserID(int newUserID); //setter for initial user id
    int getLoggedUserID();      // getter for logged user
};



#endif
