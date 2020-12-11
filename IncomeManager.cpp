#include "IncomeManager.h"


void IncomeManager::addIncome() {

    system("cls");
    cout << "Adding Income" << endl;
    cout << "--------------------------------" << endl;
    string givenDate = giveDateToNewIncome();

    string dateWithoutDashes = dispofeOfDashesInData(givenDate);

    int date = AuxiliaryMethods::convertFromStringToInt(dateWithoutDashes);


    Income income  = giveDataForNewIncome(date);
    incomes.push_back(income);
    xmlFileWithIncomes.addIncomeToXMLFile(income);

}

Income IncomeManager::giveDataForNewIncome(int givenDate){
    string strAmount;
    Income income;
    income.setIncomeID(xmlFileWithIncomes.returnLastIncomeId() + 1); //getting last id from xmfileIncomes.returnLastIncomeId() + 1;
    income.setUserID(ID_LOGGED_IN_USER);
    income.setDate(givenDate);
    cout << "Type a form of income: " ;
    income.setItem(AuxiliaryMethods::loadLine());
    cout << "Type amount of income: ";
    cin >> strAmount; //checking if bigger than 0 and making maximum two number after period
    strAmount = replaceCommasWithDots(strAmount);
    income.setAmount(AuxiliaryMethods::convertFromStringToFloat(strAmount));
    return income;
}

string IncomeManager::giveDateToNewIncome() {

    //add to method - getCurrentDate()
    cout << "Get current time" << endl;
    time_t t = time(0);
    tm* now = localtime(&t);

    char choice;
    string currentTime, strYear, strMonth, strDay;
    int intYear, intMonth, intDay;
    bool presentDay = true;
    intYear = now->tm_year + 1900;
    intMonth = now->tm_mon + 1;
    intDay = now->tm_mday;
    strYear = AuxiliaryMethods::convertFromIntToString(intYear);
    strMonth = AuxiliaryMethods::convertFromIntToString(intMonth);
    strDay = AuxiliaryMethods::convertFromIntToString(intDay);
    currentTime = strYear + '-' + strMonth + '-' + strDay;

    cout << "Select Option" << endl;
    cout << "1. Adding Income with present date: "<< currentTime << endl;
    cout <<"2. Give date from income " << endl;
    do{
         choice = AuxiliaryMethods::loadSign();
         if (choice == '2') presentDay = false;
    }while(choice != '1' && choice != '2' );

    if(!presentDay) {
        string dateInCome = "";
        string date = "";
        do {
            system("cls");
            cout << "Give data in a format rrrr-mm-dd" << endl;
            dateInCome = AuxiliaryMethods::loadLine();
            date = checkCorecctnessOfGivenDate(dateInCome);
        } while(date == "");
        return date;
    }
    return currentTime;

}
