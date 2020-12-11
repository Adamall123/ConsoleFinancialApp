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
class PersonalBudget{
   UserManager userManager;
   const string NAME_OF_FILE_WITH_INCOMES;
   const string NAME_OF_FILE_WITH_EXPENCES;
   CostsManager *costsManager;
   IncomeManager *incomeManager;
   ExpenceManager *expenceManager;
    public:
        PersonalBudget(string nameOfFileWithUsers, string nameOfFileWithIncomes, string nameOfFileWithExpences): userManager(nameOfFileWithUsers), NAME_OF_FILE_WITH_INCOMES(nameOfFileWithIncomes),NAME_OF_FILE_WITH_EXPENCES(nameOfFileWithExpences) {

        //adresatMenedzer = NULL;
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
