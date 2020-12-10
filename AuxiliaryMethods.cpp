#include "AuxiliaryMethods.h"

int AuxiliaryMethods::convertFromStringToInt(string number) {
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

char AuxiliaryMethods::loadSign() {
    string enter = "";
    char sign  = {0};

    while (true) {
        getline(cin, enter);

        if (enter.length() == 1) {
            sign = enter[0];
            break;
        }
        cout << "It's not a single character. Write it again." << endl;
    }
    return sign;
}

string AuxiliaryMethods::loadLine() {
    string enter = "";
    getline(cin, enter);

    return enter;
}
