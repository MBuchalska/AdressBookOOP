#include <iostream>
#include <fstream>
#include <string>
#include "AddressBook.h"
#include "UserManager.h"


using namespace std;

void AddressBook::UserRegister(){
user.UserRegister();
}

void AddressBook::PrintAllUsers(){
user.PrintAllUsers();
}

void AddressBook::LoginUser(){
user.LoginUser();
system("pause");
}
