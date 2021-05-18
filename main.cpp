#include <iostream>
#include "AddressBook.h"

using namespace std;

int main() {
   int ID;

    AddressBook book("Uzytkownicy.txt", "Adresaci.txt");
    book.PrintAllUsers();
    // book.UserRegister();

    book.PrintAllContactsOfLoggedUser();

    book.LoginUser();

    book.PrintAllContactsOfLoggedUser();
    book.AddNewContact();
   //book.ChangeUserPassword();
    //book.PrintAllUsers();
   // book.PrintAllContactsOfLoggedUser();
    book.LogoutUser();

    //book.LoginUser();
    //book.AddNewContact();
    //book.PrintAllContactsOfLoggedUser();

    return 0;
}
