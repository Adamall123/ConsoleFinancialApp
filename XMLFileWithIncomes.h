#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include "XMLTextFile.h"
#include "Income.h"

class XMLFileWithIncomes : public XMLTextFile{

public:
    XMLFileWithIncomes(string nameOfFile): XMLTextFile(nameOfFile) {};
    void addIncomeToXMLFile(Income income);
    vector <Income> loadIncomesFromXMLFile();

};

#endif // FILEWITHINCOMES_H
