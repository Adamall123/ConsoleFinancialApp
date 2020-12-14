#ifndef COSTSMANAGER_H
#define COSTSMANAGER_H

#include <iostream>
#include "Expence.h"
#include "Income.h"
#include <vector>
#include "XMLFileWithIncomes.h"
#include "XMLFileWithExpences.h"
#include "AuxiliaryMethods.h"

using namespace std;

class CostsManager{


protected:
    const int ID_LOGGED_IN_USER;


public:
    CostsManager(int idFromLoggedInUser) : ID_LOGGED_IN_USER(idFromLoggedInUser) {
    };

};

#endif // COSTSMANAGER_H
