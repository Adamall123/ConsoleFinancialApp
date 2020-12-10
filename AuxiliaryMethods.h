#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H


#include <iostream>
#include <sstream>
#include <algorithm>
#include <cctype>
using namespace std;

class AuxiliaryMethods{
    public:
    static char loadSign();
    static string loadLine();
    static int convertFromStringToInt(string number);
    static string convertFromIntToString(int number);

};

#endif // AUXILIARYMETHODS_H