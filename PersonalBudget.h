#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H


class PersonalBudget{

    PersonalBudget();
    ~PersonalBudget();
    void registerUser();
    void login();
    void changeOfPasswordForLoggedInUser();
    void logout();
    bool isUserLoggedIn();
    void selectOptionFromUserMenu();
    void selectOptionFromMainMenu();
    void addIncome();
    void addExpence();
    void displaySheetFromTheCurrentMonth();
    void displaySheetFromTheLastMonth();
    void displaySheetFromSelectedScopeTime();


};

#endif // PERSONALBUDGET_H
