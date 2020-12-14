#include "Costs.h"

void Costs::setUserID(int idFromLoggedInUser){
    userID = idFromLoggedInUser;
}
void Costs::setDate(int date){
    this->date = date;
}
void Costs::setItem(string item){
    this->item = item;
}
void Costs::setAmount(float amount){
    this->amount = amount;
}

int Costs::getUserId(){
    return userID;
}
 int Costs::getDate(){
    return date;
}
string Costs::getItem(){
    return item;
}
float Costs::getAmount(){
    return amount;
}
