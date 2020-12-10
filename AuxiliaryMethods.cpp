#include "AuxiliaryMethods.h"

int AuxiliaryMethods::convertFromStringToInt(string number) {
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}


string AuxiliaryMethods::convertFromIntToString(int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string AuxiliaryMethods::convertFromFloatToString(float number){
    ostringstream ss;
    ss << number;
    string s(ss.str());
    return s;
}
float AuxiliaryMethods::convertFromStringToFloat(string number){
    float amount;
    string s(number);
    char value[s.length()];
    for (int i = 0; i <sizeof(value); i++){
        value[i] = s[i];
    }
    amount = atof(value);
    return amount;
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
