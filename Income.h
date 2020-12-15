#ifndef INCOME_H
#define INCOME_H

#include "Costs.h"


class Income : public Costs {

    int incomeId;
public:
    void setIncomeID(int newId);
    int getIncomeID();

    bool operator <(Income const &r) const {
        return date < r.date;
    }

};

#endif // INCOME_H
