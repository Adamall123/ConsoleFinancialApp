#ifndef USERMANAGER_H
#define USERMANAGER_H


#include "User.h"
#include <vector>


class UserManager{

    int idLoggedInUser;
    vector <User> users;

    User giveDataForNewUser();
    int downloadNewUsersID();
    bool doesLoginExist();
public:
    UserManager();
    void registerUser();
    void login();
    void changeOfPasswordForLoggedInUser();
    void logout();
    bool isUserLoggedIn();
    void loadUsersFromXMLFile();
    int downloadLoggedInUsersID();

};



#endif // USERMANAGER_H
