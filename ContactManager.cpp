#include <iostream>
#include <vector>
#include "ContactManager.h"
#include "UserManager.h"
#include "ContactData.h"


void ContactManager::AddNewContact(int OwnerID, vector<ContactData>& contactss, int TotalNumberOfContacts) {
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

    contactss.push_back(contact);
    DaneDoZapisu=Text.ContactDataInOneLine(contact, OwnerID);
    file.addContactsToFile(DaneDoZapisu);

    cout << "Osoba zostala dodana do bazy" << endl;
    system("pause");

}

ContactManager::ContactManager() {
    USER.getLoggedUserID();
}

void ContactManager::PrintAllContactsOfLoggedUser(vector<ContactData>& contactss) {
    system("cls");
    NumberOfContacts=contactss.size();
    cout << "Wyswietlam dane wszystkich znajomych:" << endl;
    for (int i=0; i<NumberOfContacts; i++) {
        cout<<"ID: "<< contactss[i].getContactID() <<endl;
        cout<<"ID uzytnownika: "<< contactss[i].getOwnerID() <<endl; // TEMPORARY
        cout<<"Imie: "<< contactss[i].getFirstName() <<endl;
        cout<<"Nazwisko: "<< contactss[i].getLastName()<<endl;
        cout<<"Telefon: "<< contactss[i].getPhoneNumber()<<endl;
        cout<<"Mail: " << contactss[i].getMail()<<endl;
        cout<<"Adres: " << contactss[i].getAddress()<<endl;
        cout<<endl;
    }
    system("pause");
}
