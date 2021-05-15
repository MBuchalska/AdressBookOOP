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
