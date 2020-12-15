#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <stdlib.h>

#include "AuxiliaryMethods.h"
#include "UserManager.h"
#include "User.h"
#include "Costs.h"
#include "CostsManager.h"
#include "IncomeManager.h"
#include "ExpenceManager.h"
#include "DisplayCosts.h"
class PersonalBudget {
    UserManager userManager;
    const string NAME_OF_FILE_WITH_INCOMES;
    const string NAME_OF_FILE_WITH_EXPENCES;
    IncomeManager *incomeManager;
    ExpenceManager *expenceManager;
    DisplayCosts *displayCosts;
public:
    PersonalBudget(string nameOfFileWithUsers, string nameOfFileWithIncomes, string nameOfFileWithExpences):
        userManager(nameOfFileWithUsers), NAME_OF_FILE_WITH_INCOMES(nameOfFileWithIncomes),NAME_OF_FILE_WITH_EXPENCES(nameOfFileWithExpences) {
        incomeManager = NULL;
        expenceManager = NULL;
        displayCosts = NULL;
    };
    // ~PersonalBudget();
    void registerUser();
    void login();
    void changeOfPasswordForLoggedInUser();
    void logout();
    bool isUserLoggedIn();
    char selectOptionFromUserMenu();
    char selectOptionFromMainMenu();
    void addIncome();
    void addExpence();
    void displaySheetFromTheCurrentMonth();
    void displaySheetFromTheLastMonth();
    void displaySheetFromSelectedScopeTime();
};

#endif // PERSONALBUDGET_H
