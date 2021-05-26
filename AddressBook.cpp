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
    user.setLoggedUserID(0);
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
        contact->AddNewContact(ID, NumberOfContacts, LastContactID, CONTACT_FILE_NAME);
        NumberOfContacts++;
        LastContactID++;
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

void AddressBook::ChangeContactData() {
    if (user.getLoggedUserID()==0) {
        cout << "Nie zalogowano uzytkownika. Zaloguj sie zeby wyswietlic dane adresata" << endl;
        system("pause");
    } else {
        contact->ChangeContactData(CONTACT_FILE_NAME);
    }
}

void AddressBook::DeleteContact() {
    if (user.getLoggedUserID()==0) {
        cout << "Nie zalogowano uzytkownika. Zaloguj sie zeby wyswietlic dane adresata" << endl;
        system("pause");
    } else {
        NumberOfContacts=contact->DeleteContact(NumberOfContacts, CONTACT_FILE_NAME);
    }
}

bool AddressBook::IsUserLogedIn() {
    if (user.getLoggedUserID()==0) return false;
    else return true;
}

void AddressBook::FindContactByFirstName() {
    if (user.getLoggedUserID()==0) {
        cout << "Nie zalogowano uzytkownika. Zaloguj sie zeby wyswietlic dane adresata" << endl;
        system("pause");
    } else {
        contact->FindContactByFirstName();
    }
}

void AddressBook::FindContactByLastName() {
    if (user.getLoggedUserID()==0) {
        cout << "Nie zalogowano uzytkownika. Zaloguj sie zeby wyswietlic dane adresata" << endl;
        system("pause");
    } else {
        contact->FindContactByLastName();
    }
}
