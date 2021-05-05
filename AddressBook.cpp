#include <iostream>
#include <fstream>
#include "AddressBook.h"

using namespace std;


void AddressBook::UserRegister() {   //zrobic na ladnie
    fstream uzytkownicy;
    string DaneDoZapisu="";

    system("cls");
    cout << "Rejestracja nowego uzytkownika" << endl;
    cout << "Podaj dane" << endl;

    USER.UserID=numberOfUsers+1;
    DaneDoZapisu=to_string(USER.UserID);
    DaneDoZapisu+="|";

    cout << "Podaj nazwe uzytkownika: ";
    cin >> USER.UserName;
    DaneDoZapisu+=USER.UserName+"|";

    cout << "Podaj haslo do konta: ";
    cin >> USER.UserPassword;
    DaneDoZapisu+=USER.UserPassword+"|";

    users.push_back(USER);

    uzytkownicy.open("Uzytkownicy.txt.",ios::out|ios::app);
    uzytkownicy<<DaneDoZapisu<<endl;
    uzytkownicy.close();

    cout<<endl;
    cout<<"Dane uzytkownika zapisane." << endl;
    system("pause");

}
