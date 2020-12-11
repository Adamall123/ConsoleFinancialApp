#ifndef COSTSMANAGER_H
#define COSTSMANAGER_H

#include <iostream>
#include "Expence.h"
#include "Income.h"
#include <vector>
#include "XMLFileWithIncomes.h"
#include "XMLFileWithExpences.h"
#include <ctime>
#include "AuxiliaryMethods.h"

using namespace std;

class CostsManager{

protected:
    const int ID_LOGGED_IN_USER;
    string getCurrentDateFromSystem();
    int getNumberOfDaysOfSelectedMonth(int month, int year);
    string checkCorecctnessOfGivenDate(string dateIncome);
    string replaceCommasWithDots(string text);
    string dispofeOfDashesInData(string date);

public:
    CostsManager(int idFromLoggedInUser) : ID_LOGGED_IN_USER(idFromLoggedInUser) {};
};

#endif // COSTSMANAGER_H
