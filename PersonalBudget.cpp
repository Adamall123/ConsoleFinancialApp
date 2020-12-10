#include "PersonalBudget.h"


void PersonalBudget::registerUser(){
    userManager.registerUser();
}

void PersonalBudget::login(){
    userManager.login();

}
bool PersonalBudget::isUserLoggedIn(){
    if (userManager.isUserLoggedIn())
        return 1;
    else
        return 0;
}
char PersonalBudget::selectOptionFromMainMenu() {
    char choice;

    system("cls");
    cout << "    >>> Main Menu <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "9. Exit" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = AuxiliaryMethods::loadSign();
    return choice;
}

char PersonalBudget::selectOptionFromUserMenu() {
    char choice;

    system("cls");
    cout << " >>> Main User <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add Income" << endl;
    cout << "2. Add Expence" << endl;
    cout << "3. Display costs from current month" << endl;
    cout << "4. Display costs from last month" << endl;
    cout << "5. Display costs from selected scope time" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Change Password" << endl;
    cout << "7. Logout" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = AuxiliaryMethods::loadSign();

    return choice;
}
