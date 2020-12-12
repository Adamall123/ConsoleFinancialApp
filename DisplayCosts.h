#ifndef DISPLAYCOSTS_H
#define DISPLAYCOSTS_H

#include <vector>
#include "Income.h"
#include "Expence.h"
#include <cstdlib>
class DisplayCosts{
    vector <Income> incomes;
    vector <Expence> expences;
    void sortByTimeFromTheOldestTotheNewest();
    void displayDataOfIncome(Income income);
    void displayDataOfExpence(Expence expence);
public:
    DisplayCosts(vector <Income> loadedIncomes, vector <Expence> loadedExpences) : incomes(loadedIncomes), expences(loadedExpences) {};
    //in constructor file get vector of incomes and expences
    void displayBalanceSheetFromTheCurrentMonth();
    void displayBalanceSheetFromTheLastMonth();
    void displayBalanceSheetFromSelectedScopeTime();
    void giveDateScopes();
    void updateIncomes(vector <Income> newIncomes);
    void updateExpences(vector <Expence> expences);
};

#endif // DISPLAYCOSTS_H
