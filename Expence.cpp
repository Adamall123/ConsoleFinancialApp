#include "Expence.h"

void Expence::setExpenceID(int newId) {
    if(newId >= 0) {
        expenceId = newId;
    }
}
int Expence::getExpenceID() {
    return expenceId;
}
