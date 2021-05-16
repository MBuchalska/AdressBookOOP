#include <iostream>
#ifndef CONTACTDATA_H
#define CONTACTDATA_H

using namespace std;

class ContactData {
    int ContactID, OwnerID;
    string FirstName, LastName, PhoneNumber, Mail, Address;

public:
    void setContactID(int newContactID);            // setters for contact data
    void setOwnerID(int newOwnerID);
    void setFirstName(string newFirstName);
    void setLastName(string newLastName);
    void setPhoneNumber(string newPhoneNumber);
    void setMail(string newMail);
    void setAddress(string newAddress);

    int getContactID();                             // getters for contact data
    int getOwnerID();
    string getFirstName();
    string getLastName();
    string getPhoneNumber();
    string getMail();
    string getAddress();
};
#endif // CONTACTDATA_H
