#ifndef EXPENCEMANAGER_H
#define EXPENCEMANAGER_H


#include "CostsManager.h"


class ExpenceManager : private CostsManager {

    vector <Expence> expences;
    //XMLFileWithUsers xmlFileWithIncomes;

    //Czy tutaj zastosować polimorgizm?
    string giveDateToNewExpence();
    string giveItemExpence();
    string giveAmountOfExepnce();
public:
    void addExpence();


};


#endif // EXPENCEMANAGER_H
