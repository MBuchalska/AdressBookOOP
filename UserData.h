#include <iostream>


using namespace std;

class UserData {
    int UserID;
    string UserName;
    string UserPassword;

public:
    void setUserID(int newID);
    void setUserName(string newName);
    void setUserPassword(string newPassword);

    int getUserID();
    string getUserName();
    string getUserPassword();
};
