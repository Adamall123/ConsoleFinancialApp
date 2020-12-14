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

int AuxiliaryMethods::getNumberOfDaysOfSelectedMonth(int month, int year){
    const int monthOfFebruary = 2;
    if( month == monthOfFebruary) {
        if((year%400==0) || (year%4==0 && year%100!=0))
            return 29;
        else
            return 28;
    }
    //months which has 31 days
    else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8
            ||month == 10 || month==12)
        return 31;
    else
        return 30;
}
//returning int from convertet data from string to int to make it easier for sorting
string AuxiliaryMethods::checkCorecctnessOfGivenDate(string dateIncome) {
    string strYear = "", strMonth = "", strDay = "";
    int year = 2000, month = 1, day = 1;
    //it is repeated , should it be in method? returning current time and this breake for current year, month and day
    time_t t = time(0);
    tm* now = localtime(&t);

    for(int i = 0; i <dateIncome.size(); i++) {
        if (i == 4 && dateIncome[4] != '-' || i == 7 && dateIncome[7] != '-' || dateIncome.size() < 10) {
            cout << "Given a wrong format of date" << endl;
            system("pause");
            return "";
        }
        if (i < 4) {
            strYear+= dateIncome[i];
            if(i==3) {
                year = AuxiliaryMethods::convertFromStringToInt(strYear);
                int currentYear = now->tm_year + 1900;
                if(year < 2000 || year > currentYear) {
                    cout << "Given a wrong year" << endl;
                    system("pause");
                    return "";
                }
            }
        } else if (i > 4 && i < 7) {
            strMonth+= dateIncome[i];
            if (i==6) {
                month = AuxiliaryMethods::convertFromStringToInt(strMonth);
                if (month < 1 || month > 12) {
                    cout << "Given a wrong month" << endl;
                    system("pause");
                    return "";
                }
            }
        } else if(i > 7 && i < 10) {
            strDay+= dateIncome[i];
            if (i == 9) {
                day = AuxiliaryMethods::convertFromStringToInt(strDay);
                int amountDaysOfSelectedMonth = getNumberOfDaysOfSelectedMonth(month, year);
                if (day < 1 || day > amountDaysOfSelectedMonth) {
                    cout << "Given a wrong day" << endl;
                    system("pause");
                    return "";
                } else
                    return strYear + '-' + strMonth + '-' + strDay;
            }
        }
    }
}


string AuxiliaryMethods::replaceCommasWithDots(string text){
    for (int i = 0; i < text.size() ; i++){
        if(text[i] == ',') text[i] = '.';
    }
    return text;
}


string AuxiliaryMethods::disposeOfDashesInDate(string strDate) {
    string date="";
    for (int i = 0; i < strDate.size(); i++) {
        if(strDate[i] != '-')
            date+= strDate[i];
    }
    return date;
}

string AuxiliaryMethods::addDashesInDate(string date) {
    string year ="", month ="", day="";
    for (int i = 0; i < date.size(); i++) {
        if(i < 4)
            year += date[i];
        else if(i < 6)
            month += date[i];
        else if (i < 8)
            day += date[i];
    }
    return year + '-' + month + '-' + day;
}
