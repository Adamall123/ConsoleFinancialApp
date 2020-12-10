#include <iostream>
#include "PersonalBudget.h"
using namespace std;

int main()
{
    cout << "Personal Budget - start!" << endl;
    PersonalBudget personalBudget("users.xml"); //here in constructor we will give three names of xml files

    char choice;

    while (true) {
        if (!personalBudget.isUserLoggedIn()) {
            choice = personalBudget.selectOptionFromMainMenu();

            switch (choice) {
            case '1':
                personalBudget.registerUser();
                break;
            case '2':
                personalBudget.login();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "No option in this menu." << endl << endl;
                system("pause");
                break;
            }
        } else {
            choice = personalBudget.selectOptionFromUserMenu();

            switch (choice) {
            case '1':
               // ksiazkaAdresowa.dodajAdresata();
                break;
            case '2':
              //  ksiazkaAdresowa.wyszukajAdresatowPoImieniu();
                break;
            case '3':
              //  ksiazkaAdresowa.wyszukajAdresatowPoNazwisku();
                break;
            case '4':
               // ksiazkaAdresowa.wyswietlWszystkichAdresatow();
                break;
            case '5':
              //  ksiazkaAdresowa.usunAdresata();
                break;
            case '6':
             //   ksiazkaAdresowa.edytujAdresata();
                break;
            case '7':
               // ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '8':
                //ksiazkaAdresowa.wylogowanieUzytkownika();
                break;
            }
        }
    }



    return 0;
}
