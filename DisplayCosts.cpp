#include "DisplayCosts.h"

void DisplayCosts::updateIncomes(vector <Income> newIncomes) {
    incomes = newIncomes;
}
void DisplayCosts::updateExpences(vector <Expence> newExpences) {
    expences = newExpences;
}

void DisplayCosts::displayBalanceSheetFromTheCurrentMonth() {

    addToListCostsFromTheCurrentMonth();
    incomesToDisplayFromCurrentMonth = sortByTimeFromTheOldestTotheNewest(incomesToDisplayFromCurrentMonth);
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
    expencesToDisplayFromCurrentMonth = sortByTimeFromTheOldestTotheNewest(expencesToDisplayFromCurrentMonth);
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

void DisplayCosts::displayBalanceSheetFromTheLastMonth() {

    addToListCostsFromTheLastMonth();
    incomesToDisplayFromLastMonth = sortByTimeFromTheOldestTotheNewest(incomesToDisplayFromLastMonth);
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
    expencesToDisplayFromLastMonth = sortByTimeFromTheOldestTotheNewest(expencesToDisplayFromLastMonth);
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

void DisplayCosts::displayBalanceSheetFromSelectedScopeTime() {
    //give dates and check correctnes
    string strDate1 ="", strDate2="";
    int date1, date2;
    bool correctnessOfGivenTwoDates = false;
    cout << "Give Time from which period you want to display your incomes and expences" << endl;
    cout << "------------------------------------------------------------------------" << endl;
        do{
            system("cls");
            cout << "Date1: ";
            strDate1 = AuxiliaryMethods::loadLine();
        }while(AuxiliaryMethods::checkCorecctnessOfGivenDate(strDate1) == "");
        do{
            system("cls");
            cout << "Date1: " << strDate1 << endl;
            cout << "Date2: ";
            strDate2 = AuxiliaryMethods::loadLine();

            date1 = AuxiliaryMethods::convertFromStringToInt(AuxiliaryMethods::disposeOfDashesInDate(strDate1));
            date2 = AuxiliaryMethods::convertFromStringToInt(AuxiliaryMethods::disposeOfDashesInDate(strDate2));
            if (date2 >= date1)
                correctnessOfGivenTwoDates = true;
            else{
                cout << "Date 2 must be older or the same as the date 1" << endl;
                system("pause");
            }
        }while(AuxiliaryMethods::checkCorecctnessOfGivenDate(strDate2) == "" || correctnessOfGivenTwoDates == false);

    //check if date from vector include in scope

    addToListCostsBetweenTheGivenScopeTime(date1,date2);
    incomesToDisplayFromGivenScopeTime = sortByTimeFromTheOldestTotheNewest(incomesToDisplayFromGivenScopeTime);
      system("cls");
    if (!incomesToDisplayFromGivenScopeTime.empty()) {
        cout << "             >>> Incomes from: " << strDate1 <<  ": " << strDate2 << " <<<"<< endl;
        cout << "-----------------------------------------------" <<  endl;
        for (vector <Income> :: iterator itr = incomesToDisplayFromGivenScopeTime.begin(); itr != incomesToDisplayFromGivenScopeTime.end(); itr++) {
            displayDataOfIncome(*itr);
        }
        cout << endl;
    } else {
        cout << endl << "There are no incomes here" << endl << endl;
    }
    expencesToDisplayFromGivenScopeTime = sortByTimeFromTheOldestTotheNewest(expencesToDisplayFromGivenScopeTime);
    if (!expencesToDisplayFromGivenScopeTime.empty()) {
        cout << "             >>> Expences from: " << strDate1 <<  ": " << strDate2 << " <<<"<< endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Expence> :: iterator itr = expencesToDisplayFromGivenScopeTime.begin(); itr != expencesToDisplayFromGivenScopeTime.end(); itr++) {
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

void DisplayCosts::addToListCostsFromTheCurrentMonth() {
    string date;
    if (!incomes.empty()) {
        for (int i = 0; i < incomes.size(); i++) {
            date = returnCostsFromTheCurrentMonth(AuxiliaryMethods::addDashesInDate(AuxiliaryMethods::convertFromIntToString(incomes[i].getDate())));
            if(date != "")
                incomesToDisplayFromCurrentMonth.push_back(incomes[i]);
        }
        cout << endl;
    } else {
        cout << endl << "There are no incomes here" << endl << endl;
    }
    if (!expences.empty()) {
        for (int i = 0; i < expences.size(); i++) {
            date = returnCostsFromTheCurrentMonth(AuxiliaryMethods::addDashesInDate(AuxiliaryMethods::convertFromIntToString(expences[i].getDate())));
            if(date != "")
                expencesToDisplayFromCurrentMonth.push_back(expences[i]);
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

void DisplayCosts::addToListCostsFromTheLastMonth() {
    string date;
    if (!incomes.empty()) {
        for (int i = 0; i < incomes.size(); i++) {
            date = returnCostsFromLastMonth(AuxiliaryMethods::addDashesInDate(AuxiliaryMethods::convertFromIntToString(incomes[i].getDate())));
            if(date != "")
                incomesToDisplayFromLastMonth.push_back(incomes[i]);
        }
        cout << endl;
    } else {
        cout << endl << "There are no incomes here" << endl << endl;
    }
    if (!expences.empty()) {
        for (int i = 0; i < expences.size(); i++) {
            date = returnCostsFromLastMonth(AuxiliaryMethods::addDashesInDate(AuxiliaryMethods::convertFromIntToString(expences[i].getDate())));
            if(date != "")
                expencesToDisplayFromLastMonth.push_back(expences[i]);
        }
        cout << endl;
    } else {
        cout << endl << "There are no expences here" << endl << endl;
    }
}

void DisplayCosts::addToListCostsBetweenTheGivenScopeTime(int date1, int date2) {
    string date;
    if (!incomes.empty()) {
        for (int i = 0; i < incomes.size(); i++) {
           if (incomes[i].getDate() >= date1 && incomes[i].getDate() <= date2) incomesToDisplayFromGivenScopeTime.push_back(incomes[i]);
        }
        cout << endl;
    } else {
        cout << endl << "There are no incomes here" << endl << endl;
    }
    if (!expences.empty()) {
        for (int i = 0; i < expences.size(); i++) {
            if (expences[i].getDate() >= date1 && expences[i].getDate() <= date2) expencesToDisplayFromGivenScopeTime.push_back(expences[i]);
        }
        cout << endl;
    } else {
        cout << endl << "There are no expences here" << endl << endl;
    }
}



vector <Income> DisplayCosts::sortByTimeFromTheOldestTotheNewest(vector <Income> incomes){
    sort(incomes.begin(), incomes.end());
   return incomes;
}
vector <Expence> DisplayCosts::sortByTimeFromTheOldestTotheNewest(vector <Expence> expences){
    sort(expences.begin(), expences.end());
   return expences;
}
