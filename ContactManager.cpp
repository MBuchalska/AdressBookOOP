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
    DaneDoZapisu=Text.ContactDataInOneLine(contact, OwnerID);
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
