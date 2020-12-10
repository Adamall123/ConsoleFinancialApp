#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <stdlib.h>

#include "AuxiliaryMethods.h"
#include "UserManager.h"
#include "User.h"
#include "Costs.h"
#include "CostsManager.h"
#include "IncomeManager.h"
class PersonalBudget{
   UserManager userManager;
   const string NAME_OF_FILE_WITH_INCOMES;
   CostsManager *costsManager;
   IncomeManager *incomeManager;
    public:
        PersonalBudget(string nameOfFileWithUsers, string nameOfFileWithIncomes): userManager(nameOfFileWithUsers), NAME_OF_FILE_WITH_INCOMES(nameOfFileWithIncomes) {

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
