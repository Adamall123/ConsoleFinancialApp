#ifndef EXPENCE_H
#define EXPENCE_H

#include "Costs.h"

class Expence : public Costs {

    int expenceId;
public:
    void setExpenceID(int newId);
    int getExpenceID();

    bool operator <(Expence const &r) const {
        return date < r.date;
    }
};

#endif // EXPENCE_H
