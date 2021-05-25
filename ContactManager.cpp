#include <iostream>
#include <vector>
#include "ContactManager.h"
#include "UserManager.h"
#include "ContactData.h"


void ContactManager::AddNewContact(int OwnerID, int TotalNumberOfContacts, string ContactFileName) {
    string DaneDoZapisu="";
    string TempString="";
    int ContID;

    system("cls");
    cout << "Dodawanie nowego adresata" << endl;
    cout << "Podaj dane osoby" << endl;

    ContID=TotalNumberOfContacts+1;
    contact.setContactID(ContID);

    contact.setOwnerID(OwnerID);

    cout << "Imie: ";
    cin >> TempString;
    contact.setFirstName(TempString);

    cout << "Nazwisko: ";
    cin >> TempString;
    contact.setLastName(TempString);

    cout << "Telefon: ";
    cin.sync();
    getline(cin,TempString);
    contact.setPhoneNumber(TempString);

    cout << "Mail: ";
    cin >> TempString;
    contact.setMail(TempString);

    cin.sync();
    cout << "Adres: ";
    getline(cin,TempString);
    contact.setAddress(TempString);

    contacts.push_back(contact);
    DaneDoZapisu=Text.ContactDataInOneLine(contact);
    file.addContactsToFile(DaneDoZapisu, ContactFileName);

    cout << "Osoba zostala dodana do bazy" << endl;
    system("pause");

}

void ContactManager::PrintAllContactsOfLoggedUser() {
    system("cls");
    NumberOfContacts=contacts.size();
    cout << "Wyswietlam dane wszystkich znajomych:" << endl;
    for (int i=0; i<NumberOfContacts; i++) {
        cout<<"ID: "<< contacts[i].getContactID() <<endl;
        cout<<"ID uzytnownika: "<< contacts[i].getOwnerID() <<endl; // TEMPORARY
        cout<<"Imie: "<< contacts[i].getFirstName() <<endl;
        cout<<"Nazwisko: "<< contacts[i].getLastName()<<endl;
        cout<<"Telefon: "<< contacts[i].getPhoneNumber()<<endl;
        cout<<"Mail: " << contacts[i].getMail()<<endl;
        cout<<"Adres: " << contacts[i].getAddress()<<endl;
        cout<<endl;
    }
    system("pause");
}

void ContactManager::ChangeContactData(string ContactFileName) {
    int ContactNumber=0, TempID;
    char znak;
    string TempString="";
    system("cls");

    NumberOfContacts=contacts.size();

    cout << "Edycja rekordu" << endl;
    cout << "Podaj ID rekordu, ktory chcesz edytowac:" <<endl;
    cin >> TempID;
    for(int i=0; i<NumberOfContacts; i++) {
        if (contacts[i].getContactID()==TempID) {
            cout<<"ID: "<< contacts[i].getContactID() <<endl;
            cout<<"ID uzytnownika: "<< contacts[i].getOwnerID() <<endl; // TEMPORARY
            cout<<"Imie: "<< contacts[i].getFirstName() <<endl;
            cout<<"Nazwisko: "<< contacts[i].getLastName()<<endl;
            cout<<"Telefon: "<< contacts[i].getPhoneNumber()<<endl;
            cout<<"Mail: " << contacts[i].getMail()<<endl;
            cout<<"Adres: " << contacts[i].getAddress()<<endl;
            ContactNumber=i;
            cout<<endl;
        }
    }

    cout << "Ktore dane chcesz edytowac:" <<endl;
    cout << "1. Imie" <<endl;
    cout << "2. Nazwisko" <<endl;
    cout << "3. Numer telefonu"<< endl;
    cout << "4. email" << endl;
    cout << "5. Adres"<< endl;
    cout << "6. Powrot do menu" <<endl;
    cout << endl;

    cin>> znak;
    switch(znak) {
    case '1': {
        cout << "Podaj imie: ";
        cin >> TempString;
        contacts[ContactNumber].setFirstName(TempString);
        cout << "Dane zostaly zmienione" << endl;
    }
    break;
    case '2': {
        cout << "Podaj nazwisko: ";
        cin >> TempString;
        contacts[ContactNumber].setLastName(TempString);
        cout << "Dane zostaly zmienione" << endl;
    }
    break;
    case '3': {
        cout << "Podaj numer telefonu: ";
        cin.sync();
        getline(cin,TempString);
        contacts[ContactNumber].setPhoneNumber(TempString);
        cout << "Dane zostaly zmienione" << endl;
    }
    break;
    case '4': {
        cout << "Podaj mail: ";
        cin >> TempString;
        contacts[ContactNumber].setMail(TempString);
        cout << "Dane zostaly zmienione" << endl;
    }
    break;
    case '5': {
        cout << "Podaj adres: ";
        cin.sync();
        getline(cin,TempString);
        contacts[ContactNumber].setAddress(TempString);
        cout << "Dane zostaly zmienione" << endl;
    }
    break;
    case '6': {
        system("cls");
        cout << "Powrot do menu glownego" << endl;
    }
    break;
    }
    ContactData TempContact = contacts[ContactNumber];
    file.ChangeContactInFile(TempContact, ContactFileName);
}
