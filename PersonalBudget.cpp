#include "PersonalBudget.h"


void PersonalBudget::registerUser() {
    userManager.registerUser();
}

void PersonalBudget::login() {
    userManager.login();
    if(userManager.isUserLoggedIn()) {
        //costsManager = new CostsManager(NAME_OF_FILE_WITH_INCOMES, userManager.downloadLoggedInUsersID());
        incomeManager = new IncomeManager(NAME_OF_FILE_WITH_INCOMES, userManager.downloadLoggedInUsersID());
        expenceManager = new ExpenceManager(NAME_OF_FILE_WITH_EXPENCES, userManager.downloadLoggedInUsersID());
        displayCosts = new DisplayCosts(incomeManager->getIncomes(), expenceManager->getExpences());
    }
}
bool PersonalBudget::isUserLoggedIn() {
    return userManager.isUserLoggedIn();
}

void PersonalBudget::logout() {
    userManager.logout();
    //delete expences,incomes and set null;
}

void PersonalBudget::changeOfPasswordForLoggedInUser() {
    userManager.changeOfPasswordForLoggedInUser();
}

////////////////////////////////// ad income ///////////////////////////////////////////////////
void PersonalBudget::addIncome() {
    incomeManager->addIncome();
    displayCosts->updateIncomes(incomeManager->getIncomes());
}
////////////////////////////////// ad expence //////////////////////////////////////////////////
void PersonalBudget::addExpence() {
    expenceManager->addExpence();
    displayCosts->updateExpences(expenceManager->getExpences());
}
void PersonalBudget::displaySheetFromTheCurrentMonth() {
    displayCosts->displayBalanceSheetFromTheCurrentMonth();
}
void PersonalBudget::displaySheetFromTheLastMonth() {
    displayCosts->displayBalanceSheetFromTheLastMonth();
}
void PersonalBudget::displaySheetFromSelectedScopeTime() {
    displayCosts->displayBalanceSheetFromSelectedScopeTime();
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
