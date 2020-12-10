#ifndef COSTS_H
#define COSTS_H

#include <iostream>

using namespace std;

class Costs{

    protected:
    int userID;
    int date;
    string item;
    float amount;

    public:
    void setUserID(int idFromLoggedInUser);
    void setDate(int date);
    void setItem(string item);
    void setAmount(float amount);

    int getUserId();
    int getDate();
    string getItem();
    float getAmount();
};

#endif // COSTS_H
