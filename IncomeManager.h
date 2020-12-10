#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H


#include "CostsManager.h"

class IncomeManager : private CostsManager{

    vector <Income> incomes;
    //XMLFileWithUsers xmlFileWithIncomes;

    //Czy tutaj zastosować polimorgizm?
    string giveDateToNewIncome();
    string giveItemIncome();
    string giveAmountOfIncome();
public:
    void addIncome();

};

#endif // INCOMEMANAGER_H
