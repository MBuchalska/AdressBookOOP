#include <iostream>
#include <fstream>
#include <string>
#include "FileManager.h"
#include "UserData.h"


FileManager::FileManager(){}

void FileManager::addUserToFile(string line) {
    uzytkownicy.open(UserFileName,ios::out|ios::app);
    uzytkownicy<<line<<endl;
    uzytkownicy.close();
}

vector <UserData> FileManager::DownloadUsersFromFile() {
    string line;
    vector <UserData> users;
    UserData USER;
    FileManager file;

    uzytkownicy.open(UserFileName,ios::in);

    while (getline(uzytkownicy,line)) {
        USER=file.AddUserDataToVector((line));
        users.push_back(USER);
    }
    uzytkownicy.close();

    return users;
}

UserData FileManager::AddUserDataToVector(string line){
    UserData User;
    int pozycja;
    string TempString="";

    pozycja=line.find("|");
    TempString=line.substr(0,pozycja);
    int x=atoi(TempString.c_str());
    User.setUserID(x);
    line.erase(0,pozycja+1);

    pozycja=line.find("|");
    User.setUserName(line.substr(0,pozycja));
    line.erase(0,pozycja+1);

    pozycja=line.find("|");
    User.setUserPassword(line.substr(0,pozycja));
    line.erase(0,pozycja+1);

    return User;
}

void FileManager::ClearUserFile(){
    uzytkownicy.open(UserFileName,ios::out|ios::trunc);
    uzytkownicy.close();
}
