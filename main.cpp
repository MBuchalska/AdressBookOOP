#include <iostream>
#include "AddressBook.h"

using namespace std;

int main() {
    AddressBook book("Uzytkownicy.txt", "Adresaci.txt");
    char znak;

    cout << "Witaj w swojej ksiazce adresowej" << endl;

    while (true) {
        cout<< endl;
        cout << "Co chcesz zrobic:" << endl;
        cout << "1. Rejestracja nowego uzytkownika" << endl;
        cout << "2. Logowanie uzytkownika" << endl;
        cout << "3. Wypisz wszystkich uzytkownikow" <<endl;
        cout << "9. Koniec pracy" << endl;
        cin >> znak;

        system("cls");

        switch (znak) {
        case '1':
            book.UserRegister();
            break;
        case '2': {
            book.LoginUser();
            int ID = 1;              // temp wymyœl pozniej jak to poprwaic
            while (ID!=0) {
                cout << endl;
                cout << "Wybierz co chcesz zrobic" << endl;
                cout << "1. Dodaj adresata" << endl;
                // cout << "2. Wyszukaj po imieniu" << endl;
                // cout << "3. Wyszukaj po nazwisku" << endl;
                cout << "4. Wyswietl wszystkich adresatow" << endl;
                cout << "5. Usun adresata" << endl;
                cout << "6. Edytuj adresata" << endl;
                cout << "7. Zmiana hasla" << endl;
                cout << "9. Wyloguj" << endl;
                cin >> znak;

                system("cls");
                switch (znak) {
                case '1':
                    book.AddNewContact();
                    break;
                //   case '2':                 break;
                //  case '3':                 break;
                case '4':
                    book.PrintAllContactsOfLoggedUser();
                    break;
                case '5':
                    book.DeleleteContact();
                    break;
                case '6':
                    book.ChangeContactData();
                    break;
                case '7':
                    book.ChangeUserPassword();
                    break;
                case '9': {
                    book.LogoutUser();
                    ID=0;                   // temp
                }
                break;
                }
            }
        }
        break;
        case '3': {
            cout << "3. Wypisujê zarejestrowanych uzytkownikow" <<endl;
            book.PrintAllUsers();
        }
        break;

        case '9': {
            cout<<"Koniec pracy. Dziekujemy za skorzystanie z programu"<<endl;
            exit(0);
        }
        break;

        }
    }
    return 0;
}

