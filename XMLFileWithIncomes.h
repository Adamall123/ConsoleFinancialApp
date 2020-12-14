#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include "XMLTextFile.h"
#include "Income.h"

class XMLFileWithIncomes : public XMLTextFile{
    const int ID_LOGGED_IN_USER;
    int idFromLastIncome;
public:
    XMLFileWithIncomes(string nameOfFile, int idFromLoggedInUser): XMLTextFile(nameOfFile), ID_LOGGED_IN_USER(idFromLoggedInUser) {
        idFromLastIncome = 0;
    };
    void addIncomeToXMLFile(Income income);
    vector <Income> loadIncomesFromXMLFile();
    int returnLastIncomeId();

};

#endif // FILEWITHINCOMES_H
