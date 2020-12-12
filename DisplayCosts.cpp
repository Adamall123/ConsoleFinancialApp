#include "DisplayCosts.h"

void DisplayCosts::updateIncomes(vector <Income> newIncomes){
    incomes = newIncomes;
}
void DisplayCosts::updateExpences(vector <Expence> newExpences){
    expences = newExpences;
}

void DisplayCosts::displayBalanceSheetFromTheCurrentMonth(){

    system("cls");
    if (!incomes.empty()) {
        cout << "             >>> Incomes <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++) {
            displayDataOfIncome(*itr);
        }
        cout << endl;
    } else {
        cout << endl << "There are no incomes here" << endl << endl;
    }
     if (!expences.empty()) {
        cout << "             >>> Expences <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Expence> :: iterator itr = expences.begin(); itr != expences.end(); itr++) {
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
    cout << "Date:           " << expence.getDate() << endl;
}
void DisplayCosts::displayDataOfIncome(Income income) {
    cout << endl << "Item:                 " << income.getItem() << endl;
    cout << "Amount:               " << income.getAmount() << endl;
    cout << "Date:           " << income.getDate() << endl;
}
