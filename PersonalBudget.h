#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <stdlib.h>

#include "AuxiliaryMethods.h"
#include "UserManager.h"
#include "User.h"
class PersonalBudget{
   UserManager userManager;
    public:
        PersonalBudget(string nameOfFileWithUsers): userManager(nameOfFileWithUsers) {

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
