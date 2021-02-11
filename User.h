#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User {
    int userID;
    string name;
    string surname;
    string login;
    string password;
public:
    // Uzytkownik();
    void setID(int noweID );
    void setName(string name );
    void setSurname(string surname );
    void setLogin(string newLogin);
    void setPassword(string newPassword);

    int getID();
    string getName();
    string getSurname();
    string getLogin();
    string getPassword();

};

#endif // USER_H
