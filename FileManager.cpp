#include <iostream>
#include <fstream>
#include <string>
#include "FileManager.h"
#include "UserData.h"
#include "ContactData.h"


FileManager::FileManager() {}

void FileManager::addUserToFile(string line) {
    uzytkownicy.open(USER_FILE_NAME,ios::out|ios::app);
    uzytkownicy<<line<<endl;
    uzytkownicy.close();
}

vector <UserData> FileManager::DownloadUsersFromFile() {
    string line;
    vector <UserData> users;
    UserData USER;
    FileManager file;

    uzytkownicy.open(USER_FILE_NAME,ios::in);

    while (getline(uzytkownicy,line)) {
        USER=file.AddUserDataToVector((line));
        users.push_back(USER);
    }
    uzytkownicy.close();

    return users;
}

UserData FileManager::AddUserDataToVector(string line) {
    UserData User;
    int pozycja;
    string TempString="";

    pozycja=line.find("|");
    TempString=line.substr(0,pozycja);
    int x=atoi(TempString.c_str());
    User.setUserID(x);
    line.erase(0,pozycja+1);

    pozycja=line.find("|");
    User.setUserName(line.substr(0,pozycja));
    line.erase(0,pozycja+1);

    pozycja=line.find("|");
    User.setUserPassword(line.substr(0,pozycja));
    line.erase(0,pozycja+1);

    return User;
}

void FileManager::ClearUserFile() {
    uzytkownicy.open(USER_FILE_NAME,ios::out|ios::trunc);
    uzytkownicy.close();
}

void FileManager::addContactsToFile(string line, string ContactFileName) {
    znajomi.open(ContactFileName,ios::out|ios::app);
    znajomi<<line<<endl;
    znajomi.close();
}

vector <ContactData> FileManager::DownloadContactsFromFile(int LoggedUserID, string ContactFileName) {
    vector <ContactData> contacts;
    ContactData contact;
    FileManager file;
    string line;
    int licznik=0;

    znajomi.open(ContactFileName,ios::in);
    while (getline(znajomi,line)) {       // odczytuje kolejne linie dopoki getline nie zwtoci falsz
        contact=file.AddContactsToVector(line);
        licznik++;
        if (contact.getOwnerID()==LoggedUserID)  contacts.push_back(contact);
    }
    licznik=0;

    znajomi.close();

    return contacts;
}

ContactData FileManager::AddContactsToVector(string line) {
    ContactData Contact;
    int pozycja, ID;
    string TempString="";

    pozycja=line.find("|");
    TempString=line.substr(0,pozycja);
    ID=atoi(TempString.c_str());
    Contact.setContactID(ID);
    line.erase(0,pozycja+1);

    pozycja=line.find("|");
    TempString=line.substr(0,pozycja);
    ID=atoi(TempString.c_str());
    Contact.setOwnerID(ID);
    line.erase(0,pozycja+1);

    pozycja=line.find("|");
    TempString=line.substr(0,pozycja);
    Contact.setFirstName(TempString);
    line.erase(0,pozycja+1);

    pozycja=line.find("|");
    TempString=line.substr(0,pozycja);
    Contact.setLastName(TempString);
    line.erase(0,pozycja+1);

    pozycja=line.find("|");
    TempString=line.substr(0,pozycja);
    Contact.setPhoneNumber(TempString);
    line.erase(0,pozycja+1);

    pozycja=line.find("|");
    TempString=line.substr(0,pozycja);
    Contact.setMail(TempString);
    line.erase(0,pozycja+1);

    pozycja=line.find("|");
    TempString=line.substr(0,pozycja);
    Contact.setAddress(TempString);
    line.erase(0,pozycja+1);

    return Contact;
}
int FileManager::HowManyContacts(string ContactFileName) {
    int licznik=0, pozycja=0;
    string line, TempString="";
    znajomi.open(ContactFileName,ios::in);
    while (getline(znajomi,line)) {
        pozycja=line.find("|");
        TempString=line.substr(0,pozycja);
        LastContactID=atoi(TempString.c_str());
        licznik++;
    }
    znajomi.close();

    return licznik;
}

void FileManager::ChangeContactInFile(ContactData TempContact, string ContactFileName) {
    fstream znajomi2;
    string line, TempString="";
    int ID=TempContact.getContactID(), TempID=0;
    ContactData SingleContact;
    FileManager file;

    znajomi.open(ContactFileName,ios::in);
    znajomi2.open("tymczasowy.txt.",ios::out|ios::app);

    cin.sync();
    while (getline(znajomi,line)) {
        SingleContact=file.AddContactsToVector(line);
        TempID=SingleContact.getContactID();

        if(TempID==ID) {
            TempString=aux.ContactDataInOneLine(TempContact);
            znajomi2<<TempString<<endl;
        } else znajomi2<<line<<endl;
    }

    znajomi.close();
    znajomi2.close();

    remove("Adresaci.txt");             //nie chce dzialac jak sie poda zmienna
    rename("tymczasowy.txt.","Adresaci.txt");

    system("pause");

}

int FileManager::getLastContactID() {
    return LastContactID;
}

void FileManager::DeleteContactData(string ContactFileName, int ID) {
    fstream znajomi2;
    int TempID, pozycja;
    string TempString, line;

    znajomi.open(ContactFileName,ios::in);
    znajomi2.open("tymczasowy.txt.",ios::out|ios::app);

    cin.sync();
    while (getline(znajomi,line)) {
        pozycja=line.find("|");
        TempString=line.substr(0,pozycja);
        TempID=atoi(TempString.c_str());

        if (TempID!=ID) znajomi2<<line<<endl;
    }
    znajomi.close();
    znajomi2.close();

    remove("Adresaci.txt");
    rename("tymczasowy.txt.","Adresaci.txt");
}
