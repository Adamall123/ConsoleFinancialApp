#include "Income.h"

void Income::setIncomeID(int newId) {
    if(newId >= 0) {
        incomeId = newId;
    }
}
int Income::getIncomeID() {
    return incomeId;
}


