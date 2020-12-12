#include "ExpenceManager.h"

void ExpenceManager::addExpence() {

    system("cls");
    cout << "Adding Expence" << endl;
    cout << "--------------------------------" << endl;
    string givenDate = giveDateToNewExpence();

    string dateWithoutDashes = dispofeOfDashesInData(givenDate);

    int date = AuxiliaryMethods::convertFromStringToInt(dateWithoutDashes);

    Expence expence = giveDataForNewExpence(date);
    expences.push_back(expence);

    xmlFileWithExpences.addExpenceToXMLFile(expence);

}

Expence ExpenceManager::giveDataForNewExpence(int givenDate){
    string strAmount;
    Expence expence;
    expence.setExpenceID(xmlFileWithExpences.returnLastExpenceId() + 1);
    expence.setUserID(ID_LOGGED_IN_USER);
    expence.setDate(givenDate);
    cout << "Type a form of expence: " ;
    expence.setItem(AuxiliaryMethods::loadLine());
    cout << "Type amount of expence: ";
    cin >> strAmount; //checking if bigger than 0 and making maximum two number after period
    strAmount = replaceCommasWithDots(strAmount);
    expence.setAmount(AuxiliaryMethods::convertFromStringToFloat(strAmount));
    return expence;
}


string ExpenceManager::giveDateToNewExpence() {

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

vector <Expence> ExpenceManager::getExpences(){
    return expences;
}
