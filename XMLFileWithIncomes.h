#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include "XMLTextFile.h"
#include "Income.h"

class XMLFileWithIncomes : public XMLTextFile{

public:
    addExpenceToXMLFile();
    vector <Income> loadIncomesFromXMLFile();

};

#endif // FILEWITHINCOMES_H
