#include "User.h"

void User::setID(int newID){
    if(newID >= 0)
        userID = newID;
}
void User::setName( string name){
    this->name = name;
}
void User::setSurname( string surname){
    this->surname = surname;
}
void User::setLogin(string newLogin){
    login = newLogin;
}
void User::setPassword(string newPassword){
    password = newPassword;
}


int User::getID(){
    return userID;
}
string User::getLogin(){
    return login;
}
string User::getPassword(){
    return password;
}
