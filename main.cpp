#include <iostream>
#include "AddressBook.h"

using namespace std;

int main()
{
    AddressBook book("Uzytkownicy.txt");
    book.PrintAllUsers();
    book.UserRegister();
    book.UserRegister();
    book.PrintAllUsers();

    return 0;
}
