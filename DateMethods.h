#ifndef DATEMETHODS_H
#define DATEMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <ctime>
#include "AuxiliaryMethods.h"
using namespace std;

class DateMethods {

public:
    static string getCurrentDateFromSystem();
    static int getNumberOfDaysOfSelectedMonth(int month, int year);
    static string checkCorecctnessOfGivenDate(string dateIncome);
    static string disposeOfDashesInDate(string strDate);
    static string addDashesInDate(string date);
};

#endif // DATEMETHODS_H
