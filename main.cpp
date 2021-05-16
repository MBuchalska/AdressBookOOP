#include <iostream>
#include "AddressBook.h"

using namespace std;

int main() {
   int ID;

    AddressBook book("Uzytkownicy.txt", "Adresaci.txt");
    book.PrintAllUsers();
    // book.UserRegister();
    // book.UserRegister();
    book.LoginUser();
    book.AddNewContact();
   // book.ChangeUserPassword();
    book.PrintAllUsers();
    book.LogoutUser();
    book.LoginUser();
    book.AddNewContact();

    return 0;
}
