#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H


#include <iostream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <ctime>
using namespace std;

class AuxiliaryMethods{
    public:
    static char loadSign();
    static string loadLine();
    static int convertFromStringToInt(string number);
    static string convertFromIntToString(int number);
    static string convertFromFloatToString(float number);
    static float convertFromStringToFloat(string number);
    static string getCurrentDateFromSystem();
    static int getNumberOfDaysOfSelectedMonth(int month, int year);
    static string checkCorecctnessOfGivenDate(string dateIncome);
    static string replaceCommasWithDots(string text);
    static string disposeOfDashesInDate(string strDate);
    static string addDashesInDate(string date);
};

#endif // AUXILIARYMETHODS_H
