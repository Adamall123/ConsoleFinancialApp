#ifndef DISPLAYCOSTS_H
#define DISPLAYCOSTS_H

#include <vector>
#include "Income.h"
#include "Expence.h"
#include <cstdlib>
#include "AuxiliaryMethods.h"
class DisplayCosts{
    vector <Income> incomes;
    vector <Expence> expences;
    vector <Income> incomesToDisplayFromCurrentMonth;
    vector <Income> incomesToDisplayFromLastMonth;
    vector <Income> incomesToDisplayFromGivenScopeTime;
    vector <Expence> expencesToDisplayFromCurrentMonth;
    vector <Expence> expencesToDisplayFromLastMonth;
    vector <Expence> expencesToDisplayFromGivenScopeTime;
    void sortByTimeFromTheOldestTotheNewest(vector <Income> incomes);
    void sortByTimeFromTheOldestTotheNewest(vector <Expence> expences);
    void displayDataOfIncome(Income income);
    void displayDataOfExpence(Expence expence);

    string returnCostsFromTheCurrentMonth(string date);
    string returnCostsFromLastMonth(string date);// a lot of code is being repeated - think about parametter and ryling on that doing a piecie of code which is different
    void addToListCostsFromTheCurrentMonth();
    void addToListCostsFromTheLastMonth();
    void addToListCostsBetweenTheGivenScopeTime(int date1, int date2);
public:
    DisplayCosts(vector <Income> loadedIncomes, vector <Expence> loadedExpences) : incomes(loadedIncomes), expences(loadedExpences) {};
    void displayBalanceSheetFromTheCurrentMonth();
    void displayBalanceSheetFromTheLastMonth();
    void displayBalanceSheetFromSelectedScopeTime();
    void giveDateScopes();
    void updateIncomes(vector <Income> newIncomes);
    void updateExpences(vector <Expence> expences);
};

#endif // DISPLAYCOSTS_H
