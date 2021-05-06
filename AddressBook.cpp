#include <iostream>
#include <fstream>
#include <string>
#include "AddressBook.h"

using namespace std;

AddressBook::AddressBook() {
    UserFileName="Uzytkownicy.txt.";
}

void AddressBook::UserRegister() {
    fstream uzytkownicy;
    string DataInOneLine="";
    int ID;
    string TempString="";

    numberOfUsers=users.size();

    system("cls");
    cout << "Rejestracja nowego uzytkownika" << endl;
    cout << "Podaj dane" << endl;

    ID=numberOfUsers+1;
    USER.setUserID(ID);
    int x=USER.getUserID();
    DataInOneLine=to_string(x);
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

    uzytkownicy.open(UserFileName,ios::out|ios::app);
    uzytkownicy<<DataInOneLine<<endl;
    uzytkownicy.close();

    cout<<endl;
    cout<<"Dane uzytkownika zapisane." << endl;
    system("pause");
}

void AddressBook::PrintAllUsers() {
    for (int i=0; i<users.size(); i++) {
        cout << "ID: " << users[i].getUserID() << endl;
        cout << "Nazwa uzytkownika: " << users[i].getUserName() << endl;
        cout << "Haslo: " << users[i].getUserPassword() << endl;
    }
}
