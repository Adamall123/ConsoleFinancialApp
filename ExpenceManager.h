#ifndef EXPENCEMANAGER_H
#define EXPENCEMANAGER_H


#include "CostsManager.h"


class ExpenceManager : private CostsManager {

    vector <Expence> expences;
    XMLFileWithExpences xmlFileWithExpences;
    //Czy tutaj zastosować polimorgizm?
    Expence giveDataForNewExpence(int givenDate);
    string giveDateToNewExpence();

public:
    ExpenceManager(string nameOfFile, int idLoggedInUser) : xmlFileWithExpences(nameOfFile), CostsManager(idLoggedInUser){
        expences = xmlFileWithExpences.loadExpencesFromXMLFile();
    };
    void addExpence();


};


#endif // EXPENCEMANAGER_H
