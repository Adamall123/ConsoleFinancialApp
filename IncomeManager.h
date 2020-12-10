#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H


#include "CostsManager.h"
#include <cstdlib>
#include <string.h>

class IncomeManager : private CostsManager{

    vector <Income> incomes;
    XMLFileWithIncomes xmlFileWithIncomes;
    //XMLFileWithUsers xmlFileWithIncomes;

    //Czy tutaj zastosować polimorgizm?
    string giveDateToNewIncome();
    Income giveDataForNewIncome(int givenDate);
    string replaceCommasWithDots(string text);
    //string giveItemIncome();
    //string giveAmountOfIncome();
public:
    /*CostsManager(string nameOfFile, int idFromLoggedInUser) : xmlFileWithIncomes(nameOfFile), ID_LOGGED_IN_USER(idFromLoggedInUser) {
    //adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    };*/
    IncomeManager(string nameOfFile, int iDFromLoggedInUser) : xmlFileWithIncomes(nameOfFile), CostsManager(iDFromLoggedInUser){
        incomes = xmlFileWithIncomes.loadIncomesFromXMLFile();
        //cout << incomes.size() << endl;
        //system("pause");
    };
    void addIncome();

};

#endif // INCOMEMANAGER_H
