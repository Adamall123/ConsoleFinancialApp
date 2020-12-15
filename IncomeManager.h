#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H


#include "CostsManager.h"
#include <cstdlib>
#include <string.h>

class IncomeManager : private CostsManager {

    vector <Income> incomes;
    XMLFileWithIncomes xmlFileWithIncomes;

    string giveDateToNewIncome();
    Income giveDataForNewIncome(int givenDate);

public:
    IncomeManager(string nameOfFile, int iDFromLoggedInUser) : xmlFileWithIncomes(nameOfFile, iDFromLoggedInUser), CostsManager(iDFromLoggedInUser) {
        incomes = xmlFileWithIncomes.loadIncomesFromXMLFile();
    };
    void addIncome();
    vector <Income> getIncomes();

};

#endif // INCOMEMANAGER_H
