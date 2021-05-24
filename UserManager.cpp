#include <iostream>
#include "UserManager.h"
#include "FileManager.h"
#include "auxiliary.h"


UserManager::UserManager() {
};

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

    cout << "Podaj nazwe uzytkownika: ";
    cin >> TempString;
    USER.setUserName(TempString);

    cout << "Podaj haslo do konta: ";
    cin >> TempString;
    USER.setUserPassword(TempString);

    users.push_back(USER);
    DataInOneLine=DataInLine.UserDataInOneLine(USER);
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
        cout << endl;
    }
    system("pause");
}

int UserManager::LoginUser() {
    string TempLogin="", TempPassword="", login="", pass="";

    system("cls");
    numberOfUsers=users.size();
    cout << "Logowanie" << endl;
    cout << "Podaj nazwe uzytkownika: " ;
    cin >> TempLogin;
    cout <<endl;

    for (int i=0; i<numberOfUsers; i++) {
        USER=users[i];
        login = USER.getUserName();
        pass = USER.getUserPassword();

        if (login==TempLogin) {
            cout << "Znaleziono login w bazie." << endl;
            for (int j=3; j>0; j--) {
                cout << "Podaj haslo: ";
                cin >> TempPassword;
                cout<<endl;

                if (pass==TempPassword) {
                    cout << "Logowanie poprawne" <<endl;
                    cout << "Witaj " << login << endl;
                    LoggedUserID=USER.getUserID();
                    cout<< LoggedUserID << endl;  // temp
                    cout << "Wyswietlam dane wszystkich znajomych:" << endl;
                    return LoggedUserID;

                } else {
                    cout << "Haslo niepoprawne. Pozostalo prob: " << j-1 << endl;
                }
            }
            cout << "Logowanie nieudane. Podano 3 razy niepoprawne haslo." << endl;
            return 0;
        }
    }
    cout << "Logowanie nieudane. Nie ma takiego uzytkownika w bazie." << endl;
    return 0;
}

void UserManager::ChangeUserPassword() {
    if (LoggedUserID==0) {
        cout << "Uzytkownik nie jest zalogowany. Zaloguj sie zeby zmienic haslo" << endl;
        system("pause");
    }

    else {
        string DataInOneLine="", TempPass="";
        int TempUserID;
        numberOfUsers=users.size();

        system("cls");
        file.ClearUserFile();

        cout<< "Zmiana hasla" << endl;

        for (int i=0; i<numberOfUsers; i++) {
            DataInOneLine="";
            USER=users[i];
            TempUserID=USER.getUserID();
            if (TempUserID==LoggedUserID) {
                cout<< "Podaj swoje nowe haslo:";
                cin >> TempPass;
                USER.setUserPassword(TempPass);
                users[i]=USER;
                cout <<endl;
                cout <<"Haslo zostalo zmienione" << endl;
            }

            DataInOneLine=DataInLine.UserDataInOneLine(USER);
            file.addUserToFile(DataInOneLine);
        }
        system("pause");
    }
}

UserManager::~UserManager(){
LoggedUserID=0;
}

void UserManager::setLoggedUserID(int newUserID){
LoggedUserID=newUserID;
}

int UserManager::getLoggedUserID(){
return LoggedUserID;
}
