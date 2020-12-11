#ifndef EXPENCE_H
#define EXPENCE_H

#include "Costs.h"

class Expence : public Costs{

    int expenceId;
public:
    void setExpenceID(int newId);
    int getExpenceID();
};

#endif // EXPENCE_H
