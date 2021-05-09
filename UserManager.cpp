#include <iostream>
#include "UserManager.h"
#include "FileManager.h"


void UserManager::UserRegister() {
    string DataInOneLine="";
    string TempString="";
    int ID;

    numberOfUsers=users.size();

    system("cls");
    cout << "Rejestracja nowego uzytkownika" << endl;
    cout << "Podaj dane" << endl;

    ID=numberOfUsers+1;
    USER.setUserID(ID);
    ID=USER.getUserID();
    DataInOneLine=to_string(ID);
    DataInOneLine+="|";

    cout << "Podaj nazwe uzytkownika: ";
    cin >> TempString;
    USER.setUserName(TempString);
    DataInOneLine+=USER.getUserName()+"|";

    cout << "Podaj haslo do konta: ";
    cin >> TempString;
    USER.setUserPassword(TempString);
    DataInOneLine+=USER.getUserPassword()+"|";

    users.push_back(USER);

    file.addUserToFile(DataInOneLine);

    cout<<endl;
    cout<<"Dane uzytkownika zapisane." << endl;
    system("pause");
}

    void UserManager::PrintAllUsers() {
    for (int i=0; i<users.size(); i++) {
        cout << "ID: " << users[i].getUserID() << endl;
        cout << "Nazwa uzytkownika: " << users[i].getUserName() << endl;
        cout << "Haslo: " << users[i].getUserPassword() << endl;
    }
}
