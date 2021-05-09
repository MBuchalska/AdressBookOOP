#include <iostream>
#include <fstream>
#include "FileManager.h"


FileManager::FileManager(){
UserFileName="Uzytkownicy.txt";
}

void FileManager::addUserToFile(string line) {
    fstream uzytkownicy;
    uzytkownicy.open(UserFileName,ios::out|ios::app);
    uzytkownicy<<line<<endl;
    uzytkownicy.close();
}
