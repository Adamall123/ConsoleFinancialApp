#ifndef COSTSMANAGER_H
#define COSTSMANAGER_H

#include <iostream>
#include "Expence.h"
#include "Income.h"
#include <vector>
#include "XMLFileWithIncomes.h"
#include <ctime>
#include "AuxiliaryMethods.h"

using namespace std;

class CostsManager{

protected:

    const int ID_LOGGED_IN_USER;
    string getCurrentDateFromSystem();
    int getNumberOfDaysOfSelectedMonth(int month, int year);
    string checkCorecctnessOfGivenDate(string dateIncome);
    void replaceCommaWithPeriod();
    string replaceCommasWithDots(string text);
public:
    CostsManager(int idFromLoggedInUser) : ID_LOGGED_IN_USER(idFromLoggedInUser) {
    //adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    };
};

#endif // COSTSMANAGER_H
