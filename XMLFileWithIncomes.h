#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include "XMLTextFile.h"
#include "Income.h"

class XMLFileWithIncomes : public XMLTextFile{

    int idFromLastIncome;
public:
    XMLFileWithIncomes(string nameOfFile): XMLTextFile(nameOfFile) {
        idFromLastIncome = 0;
    };
    void addIncomeToXMLFile(Income income);
    vector <Income> loadIncomesFromXMLFile();
    int returnLastIncomeId();

};

#endif // FILEWITHINCOMES_H
