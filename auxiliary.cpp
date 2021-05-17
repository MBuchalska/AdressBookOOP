#include <iostream>
#include "auxiliary.h"
#include "UserData.h"


string Auxiliary::UserDataInOneLine(UserData USER) {
    string DataInOneLine="";
    DataInOneLine=to_string(USER.getUserID());
    DataInOneLine+="|";
    DataInOneLine+=USER.getUserName()+"|";
    DataInOneLine+=USER.getUserPassword()+"|";

    return DataInOneLine;
}

string Auxiliary::ContactDataInOneLine(ContactData contact, int OwnerID) {
    string DataInOneLine="";

    int ContID=contact.getContactID();
    DataInOneLine=to_string(ContID);
    DataInOneLine+="|";

    DataInOneLine+=to_string(OwnerID);
    DataInOneLine+="|";

    DataInOneLine+=contact.getFirstName()+"|";
    DataInOneLine+=contact.getLastName()+"|";
    DataInOneLine+=contact.getPhoneNumber()+"|";
    DataInOneLine+=contact.getMail()+"|";
    DataInOneLine+=contact.getAddress()+"|";

    return DataInOneLine;
}
