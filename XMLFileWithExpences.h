#ifndef XMLFILEWITHEXPENCES_H
#define XMLFILEWITHEXPENCES_H

#include "XMLTextFile.h"
#include "Expence.h"
class XMLFileWithExpences : public XMLTextFile{

public:
    addExpenceToXMLFile();
    vector <Expence> loadExpencesFromXMLFile();

};

#endif // XMLFILEWITHEXPENCES_H
