#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H


#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class AuxiliaryMethods {
public:
    static char loadSign();
    static string loadLine();
    static int convertFromStringToInt(string number);
    static string convertFromIntToString(int number);
    static string convertFromFloatToString(float number);
    static float convertFromStringToFloat(string number);
    static string replaceCommasWithDots(string text);

};

#endif // AUXILIARYMETHODS_H
