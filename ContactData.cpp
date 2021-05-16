#include <iostream>
#include "ContactData.h"


void ContactData::setContactID(int newContactID){
ContactID=newContactID;
}

void ContactData::setOwnerID(int newOwnerID){
OwnerID=newOwnerID;
}

void ContactData::setFirstName(string newFirstName){
FirstName=newFirstName;
}

void ContactData::setLastName(string newLastName){
LastName=newLastName;
}

void ContactData::setPhoneNumber(string newPhoneNumber){
PhoneNumber=newPhoneNumber;
}

void ContactData::setMail(string newMail){
Mail=newMail;
}

void ContactData::setAddress(string newAddress){
Address=newAddress;
}

int ContactData::getContactID(){
return ContactID;
}

int ContactData::getOwnerID(){
return OwnerID;
}

string ContactData::getFirstName(){
return FirstName;
}

string ContactData::getLastName(){
return LastName;
}

string ContactData::getPhoneNumber(){
return PhoneNumber;
}

string ContactData::getMail(){
return Mail;
}

string ContactData::getAddress(){
return Address;
}
