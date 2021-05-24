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
    if (ID>0) {
        contact = new ContactManager(CONTACT_FILE_NAME, ID);
    }
}

void AddressBook::ChangeUserPassword() {
    user.ChangeUserPassword();
}

void AddressBook::LogoutUser() {
    user.~UserManager();
    delete contact;
    contact = NULL;
    cout << "Uzytkownik zostal wylogowany. Dziekujemy za skorzystanie z programu"<<endl;
    system("pause");
}

void AddressBook::AddNewContact() {
    if (user.getLoggedUserID()==0) {
        cout << "Nie zalogowano uzytkownika. Zaloguj sie zeby dodaæ adresata" << endl;
        system("pause");
    } else {
    int ID=user.getLoggedUserID();
    contact->AddNewContact(ID, NumberOfContacts, CONTACT_FILE_NAME);
    NumberOfContacts++;
    }
}

void AddressBook::PrintAllContactsOfLoggedUser() {
    if (user.getLoggedUserID()==0) {
        cout << "Nie zalogowano uzytkownika. Zaloguj sie zeby wyswietlic dane adresata" << endl;
        system("pause");
    } else {
        contact->PrintAllContactsOfLoggedUser();
    }
}
