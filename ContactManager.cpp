#include <iostream>
#include <vector>
#include "ContactManager.h"
#include "UserManager.h"
#include "ContactData.h"


void ContactManager::AddNewContact(int OwnerID){

NumberOfContacts = contacts.size();
  //      fstream znajomi;

    string DaneDoZapisu="";
    string TempString="";
    int ContID;

    system("cls");
    cout << "Dodawanie nowego adresata" << endl;
    cout << "Podaj dane osoby" << endl;

    ContID=NumberOfContacts+1;
    contact.setContactID(ContID);
   // ContID=contact.getContactID();
 // DaneDoZapisu=to_string(ContID);
 //   DaneDoZapisu+="|";

 //  DaneDoZapisu+=to_string(OwnerID);
  //  DaneDoZapisu+="|";

    cout << "Imie: ";
    cin >> TempString;
    contact.setFirstName(TempString);
  //  DaneDoZapisu+=contact.getFirstName()+"|";

    cout << "Nazwisko: ";
    cin >> TempString;
    contact.setLastName(TempString);
   // DaneDoZapisu+=contact.getLastName()+"|";

    cout << "Telefon: ";
    cin.sync();
    getline(cin,TempString);
    contact.setPhoneNumber(TempString);
  //  DaneDoZapisu+=contact.getPhoneNumber()+"|";

    cout << "Mail: ";
    cin >> TempString;
    contact.setMail(TempString);
   // DaneDoZapisu+=contact.getMail()+"|";

    cin.sync();
    cout << "Adres: ";
    getline(cin,TempString);
    contact.setAddress(TempString);
  //  DaneDoZapisu+=contact.getAddress()+"|";

    contacts.push_back(contact);
   DaneDoZapisu=Text.ContactDataInOneLine(contact, OwnerID);
   file.addContactsToFile(DaneDoZapisu);

    cout << "Osoba zostala dodana do bazy" << endl;
    system("pause");

}

ContactManager::ContactManager(){
USER.getLoggedUserID();
}
