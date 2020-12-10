#include "IncomeManager.h"


void IncomeManager::addIncome() {

    //dotyczy dnia dzisiejszego czy inną z datą chcesz dodać
    //jeśli wybierze dzisiejszy to pobierz z systemu dzisiejsza date
    //jeśli nie to wpiś date w formacie rrrr-mm-dd
    system("cls");
    cout << "Adding Income" << endl;
    cout << "--------------------------------" << endl;
    string givenDate = giveDateToNewIncome();

    //////////////////////////////////////////////////////////////
    //disposfe of '-' from string in date
    string dateToConvert="";
    for (int i = 0; i < givenDate.size(); i++){
        if(givenDate[i] != '-') dateToConvert+=givenDate[i];
    }
    //////////////////////////////////////////////////////////////

    int date = AuxiliaryMethods::convertFromStringToInt(dateToConvert);

    //change givenDate to Integer
    Income income  = giveDataForNewIncome(date);

    incomes.push_back(income);
    /*
    for (int i = 0; i < incomes.size(); i++){
        cout << incomes[i].getUserId() << endl;
        cout << incomes[i].getDate() << endl;
        cout << incomes[i].getItem() << endl;
        cout << incomes[i].getAmount() << endl;
    }
    system("PAUSE");
    */

    xmlFileWithIncomes.addIncomeToXMLFile(income);

}

string IncomeManager::replaceCommasWithDots(string text){
    for (int i = 0; i < text.size() ; i++){
        if(text[i] == ',') text[i] = '.';
    }
    return text;
}

Income IncomeManager::giveDataForNewIncome(int givenDate){
    //return lastID of Income - method to do...
    //czegho dotyczy przychod
    //wysokosc przychody
    //kwoty ułamkowe zapisuj z kropką jeśli ktoś wpisze ułamek z przecinkiem to zamień przecinek na kropke
    string strAmount;
    float amount;
    Income income;
    income.setIncomeID(1); //getting last id from xmfileIncomes.getLastIncomeId();
    income.setUserID(ID_LOGGED_IN_USER);
    income.setDate(givenDate);
    cout << "Type a form of income: " ;
    income.setItem(AuxiliaryMethods::loadLine());
    cout << "Type amount of income: ";
    cin >> strAmount; //checking if bigger than 0 and making maximum two number after period
    strAmount = replaceCommasWithDots(strAmount);
    //////////////////////////////////////////////////////////////////////
    //change string to list of characters - write a method
    string s(strAmount);
    char value[s.length()];
    for (int i = 0; i <sizeof(value); i++){
        value[i] = s[i];
    }
    amount = atof(value);
    //////////////////////////////////////////////////////////////////////

    income.setAmount(amount);


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
