#include <iostream>
#ifndef USERDATA_h
#define USERDATA_h


using namespace std;

class UserData {
    int UserID;
    string UserName;
    string UserPassword;

public:
    void setUserID(int newID);                  // set of setters
    void setUserName(string newName);
    void setUserPassword(string newPassword);

    int getUserID();                            // set of getters
    string getUserName();
    string getUserPassword();
};

#endif // USERDATA_h
