#ifndef COSTSMANAGER_H
#define COSTSMANAGER_H

#include <iostream>
#include "Expence.h"
#include "Income.h"
#include <vector>
using namespace std;

class CostsManager{

    const int ID_LOGGED_IN_USER;

protected:
    string getCurrentDateFromSystem();
    int getNumberOfDaysOfSelectedMonth();
    bool checkCorectnessOfGivenDate();
    void replaceCommaWithPeriod();
};

#endif // COSTSMANAGER_H
