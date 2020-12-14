#ifndef XMLFILEWITHEXPENCES_H
#define XMLFILEWITHEXPENCES_H

#include "XMLTextFile.h"
#include "Expence.h"
class XMLFileWithExpences : public XMLTextFile{
    const int ID_LOGGED_IN_USER;
    int idFromLastExpence;
public:
    XMLFileWithExpences(string nameOfFile, int idFromLoggedInUser): XMLTextFile(nameOfFile), ID_LOGGED_IN_USER(idFromLoggedInUser) {
        idFromLastExpence = 0;
    };

    void addExpenceToXMLFile(Expence expence);
    int returnLastExpenceId();
    vector <Expence> loadExpencesFromXMLFile();

};

#endif // XMLFILEWITHEXPENCES_H
