#include <iostream>
#include <fstream>
#include <string>
#include "AddressBook.h"
#include "UserManager.h"
#include "ContactManager.h"


using namespace std;

void AddressBook::UserRegister() {
    user.UserRegister();
}

void AddressBook::PrintAllUsers() {
    user.PrintAllUsers();
}

void AddressBook::LoginUser() {
    int ID=user.LoginUser();
    system("pause");
}

void AddressBook::ChangeUserPassword() {
    user.ChangeUserPassword();
}

void AddressBook::LogoutUser() {
    user.~UserManager();
    cout << "Uzytkownik zostal wylogowany. Dziekujemy za skorzystanie z programu"<<endl;
    system("pause");
}

void AddressBook::AddNewContact() {
    if (user.getLoggedUserID()==0) {
        cout << "Nie zalogowano uzytkownika. Zaloguj sie zeby wyswietlic dane adresata" << endl;
        system("pause");
    } else {
        int ID;
        ID=user.getLoggedUserID();
        contact.AddNewContact(ID);
    }

}
