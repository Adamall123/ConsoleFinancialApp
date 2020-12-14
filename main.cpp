#include <iostream>
#include "PersonalBudget.h"
using namespace std;

int main()
{
    cout << "Personal Budget - start!" << endl;
    PersonalBudget personalBudget("users.xml", "incomes.xml","expences.xml");

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
                    personalBudget.addIncome();
                break;
            case '2':
                    personalBudget.addExpence();
                break;
            case '3':
                    personalBudget.displaySheetFromTheCurrentMonth();
                break;
            case '4':
                    personalBudget.displaySheetFromTheLastMonth();
                break;
            case '5':
              //  ksiazkaAdresowa.usunAdresata();
                break;
            case '6':
                personalBudget.changeOfPasswordForLoggedInUser();
                break;
            case '7':
                personalBudget.logout();
                break;
            }
        }
    }



    return 0;
}
