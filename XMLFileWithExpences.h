#ifndef XMLFILEWITHEXPENCES_H
#define XMLFILEWITHEXPENCES_H

#include "XMLTextFile.h"
#include "Expence.h"
class XMLFileWithExpences : public XMLTextFile{
    int idFromLastExpence;
public:
    XMLFileWithExpences(string nameOfFile): XMLTextFile(nameOfFile) {
        idFromLastExpence = 0;
    };

    void addExpenceToXMLFile(Expence expence);
    int returnLastExpenceId();
    vector <Expence> loadExpencesFromXMLFile();

};

#endif // XMLFILEWITHEXPENCES_H
