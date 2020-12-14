#include "DisplayCosts.h"

void DisplayCosts::updateIncomes(vector <Income> newIncomes){
    incomes = newIncomes;
}
void DisplayCosts::updateExpences(vector <Expence> newExpences){
    expences = newExpences;
}

void DisplayCosts::displayBalanceSheetFromTheCurrentMonth(){

    addToListCostsFromTheCurrentMonth();
    system("cls");
    if (!incomesToDisplayFromCurrentMonth.empty()) {
        cout << "             >>> Incomes from the current month <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Income> :: iterator itr = incomesToDisplayFromCurrentMonth.begin(); itr != incomesToDisplayFromCurrentMonth.end(); itr++) {
            displayDataOfIncome(*itr);
        }
        cout << endl;
    } else {
        cout << endl << "There are no incomes here" << endl << endl;
    }
     if (!expencesToDisplayFromCurrentMonth.empty()) {
        cout << "             >>> Expences from the current month <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Expence> :: iterator itr = expencesToDisplayFromCurrentMonth.begin(); itr != expencesToDisplayFromCurrentMonth.end(); itr++) {
            displayDataOfExpence(*itr);
        }
        cout << endl;
    } else {
        cout << endl << "There are no expences here" << endl << endl;
    }

    system("pause");
}

void DisplayCosts::displayBalanceSheetFromTheLastMonth(){

    addToListCostsFromTheLastMonth();
    system("cls");
    if (!incomesToDisplayFromLastMonth.empty()) {
        cout << "             >>> Incomes from the last month <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Income> :: iterator itr = incomesToDisplayFromLastMonth.begin(); itr != incomesToDisplayFromLastMonth.end(); itr++) {
            displayDataOfIncome(*itr);
        }
        cout << endl;
    } else {
        cout << endl << "There are no incomes here" << endl << endl;
    }
     if (!expencesToDisplayFromLastMonth.empty()) {
        cout << "             >>> Expences from the last month <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Expence> :: iterator itr = expencesToDisplayFromLastMonth.begin(); itr != expencesToDisplayFromLastMonth.end(); itr++) {
            displayDataOfExpence(*itr);
        }
        cout << endl;
    } else {
        cout << endl << "There are no expences here" << endl << endl;
    }

    system("pause");
}



void DisplayCosts::displayDataOfExpence(Expence expence) {
    cout << endl << "Item:                 " << expence.getItem() << endl;
    cout << "Amount:               " << expence.getAmount() << endl;
    cout << "Date:           " << AuxiliaryMethods::addDashesInDate(AuxiliaryMethods::convertFromIntToString(expence.getDate())) << endl;
}
void DisplayCosts::displayDataOfIncome(Income income) {
    cout << endl << "Item:                 " << income.getItem() << endl;
    cout << "Amount:               " << income.getAmount() << endl;
    cout << "Date:           " << AuxiliaryMethods::addDashesInDate(AuxiliaryMethods::convertFromIntToString(income.getDate())) << endl;
}

void DisplayCosts::addToListCostsFromTheCurrentMonth(){
    string date;
    if (!incomes.empty()) {
        for (int i = 0; i < incomes.size(); i++) {
           date = returnCostsFromTheCurrentMonth(AuxiliaryMethods::addDashesInDate(AuxiliaryMethods::convertFromIntToString(incomes[i].getDate())));
            if(date != "") incomesToDisplayFromCurrentMonth.push_back(incomes[i]);
        }
        cout << endl;
    } else {
        cout << endl << "There are no incomes here" << endl << endl;
    }
     if (!expences.empty()) {
         for (int i = 0; i < expences.size(); i++) {
            date = returnCostsFromTheCurrentMonth(AuxiliaryMethods::addDashesInDate(AuxiliaryMethods::convertFromIntToString(expences[i].getDate())));
            if(date != "") expencesToDisplayFromCurrentMonth.push_back(expences[i]);
        }
        cout << endl;
    } else {
        cout << endl << "There are no expences here" << endl << endl;
    }
}

string DisplayCosts::returnCostsFromTheCurrentMonth(string date) {
    string strYear = "", strMonth = "", strDay = "";
    int year = 2000, month = 1, day = 1;
    time_t t = time(0);
    tm* now = localtime(&t);

    for(int i = 0; i <date.size(); i++) {
        if (i < 4) {
            strYear+= date[i];
            if(i==3) {
                year = AuxiliaryMethods::convertFromStringToInt(strYear);
                int currentYear = now->tm_year + 1900;
                if(year != currentYear) {
                    return "";
                }
            }
        } else if (i > 4 && i < 7) {
            strMonth+= date[i];
            if (i==6) {
                month = AuxiliaryMethods::convertFromStringToInt(strMonth);
                int currentMonth = now->tm_mon + 1;
                if (month != currentMonth ) {
                    return "";
                }
            }
        } else if(i > 7 && i < 10) {
            strDay+= date[i];
            if (i == 9) {
                day = AuxiliaryMethods::convertFromStringToInt(strDay);
                int amountDaysOfSelectedMonth = AuxiliaryMethods::getNumberOfDaysOfSelectedMonth(month, year);
                if (day < 1 || day > amountDaysOfSelectedMonth) {
                    return "";
                } else
                    return strYear + '-' + strMonth + '-' + strDay;
            }
        }
    }
}
// a lot of code is being repeated - think about parametter and ryling on that doing a piecie of code which is different
string DisplayCosts::returnCostsFromLastMonth(string date) {
    string strYear = "", strMonth = "", strDay = "";
    int year = 2000, month = 1, day = 1;
    time_t t = time(0);
    tm* now = localtime(&t);

    for(int i = 0; i <date.size(); i++) {
        if (i < 4) {
            strYear+= date[i];
            if(i==3) {
                year = AuxiliaryMethods::convertFromStringToInt(strYear);
                int currentYear = now->tm_year + 1900;
                if(year != currentYear) {
                    return "";
                }
            }
        } else if (i > 4 && i < 7) {
            strMonth+= date[i];
            if (i==6) {
                month = AuxiliaryMethods::convertFromStringToInt(strMonth);
                int currentMonth = now->tm_mon + 1;
                if (month != currentMonth - 1 ) { //only here is different piece of code
                    return "";
                }
            }
        } else if(i > 7 && i < 10) {
            strDay+= date[i];
            if (i == 9) {
                day = AuxiliaryMethods::convertFromStringToInt(strDay);
                int amountDaysOfSelectedMonth = AuxiliaryMethods::getNumberOfDaysOfSelectedMonth(month, year);
                if (day < 1 || day > amountDaysOfSelectedMonth) {
                    return "";
                } else
                    return strYear + '-' + strMonth + '-' + strDay;
            }
        }
    }
}

void DisplayCosts::addToListCostsFromTheLastMonth(){
    string date;
    if (!incomes.empty()) {
        for (int i = 0; i < incomes.size(); i++) {
           date = returnCostsFromLastMonth(AuxiliaryMethods::addDashesInDate(AuxiliaryMethods::convertFromIntToString(incomes[i].getDate())));
            if(date != "") incomesToDisplayFromLastMonth.push_back(incomes[i]);
        }
        cout << endl;
    } else {
        cout << endl << "There are no incomes here" << endl << endl;
    }
     if (!expences.empty()) {
         for (int i = 0; i < expences.size(); i++) {
            date = returnCostsFromLastMonth(AuxiliaryMethods::addDashesInDate(AuxiliaryMethods::convertFromIntToString(expences[i].getDate())));
            if(date != "") expencesToDisplayFromLastMonth.push_back(expences[i]);
        }
        cout << endl;
    } else {
        cout << endl << "There are no expences here" << endl << endl;
    }
}

