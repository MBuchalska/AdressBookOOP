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
    contacts=file.DownloadContactsFromFile(ID);
}

void AddressBook::ChangeUserPassword() {
    user.ChangeUserPassword();
}

void AddressBook::LogoutUser() {
    user.~UserManager();
    contacts.clear();
    cout << "Uzytkownik zostal wylogowany. Dziekujemy za skorzystanie z programu"<<endl;
    system("pause");
}

void AddressBook::AddNewContact() {
    if (user.getLoggedUserID()==0) {
        cout << "Nie zalogowano uzytkownika. Zaloguj sie zeby dodaæ adresata" << endl;
        system("pause");
    } else {
    int ID=user.getLoggedUserID();
    contact.AddNewContact(ID, contacts, NumberOfContacts);
    NumberOfContacts++;
    }
}

void AddressBook::PrintAllContactsOfLoggedUser() {
    if (user.getLoggedUserID()==0) {
        cout << "Nie zalogowano uzytkownika. Zaloguj sie zeby wyswietlic dane adresata" << endl;
        system("pause");
    } else {
        contact.PrintAllContactsOfLoggedUser(contacts);
    }
}
