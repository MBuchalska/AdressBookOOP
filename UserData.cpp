#include <iostream>
#include "UserData.h"

using namespace std;


    void UserData::setUserID(int newID){
    UserID=newID;
    }
    void UserData::setUserName(string newName){
    UserName=newName;
    }
    void UserData::setUserPassword(string newPassword){
    UserPassword=newPassword;
    }
        int UserData::getUserID(){
    return UserID;
    }
    string UserData::getUserName(){
    return UserName;
    }
    string UserData::getUserPassword(){
    return UserPassword;
    }
