#ifndef USERMANAGER_H
#define USERMANAGER_H


#include "User.h"
#include <vector>
#include <stdlib.h>
#include "AuxiliaryMethods.h"
#include "XMLFileWithUsers.h"

class UserManager {

    int idLoggedInUser;
    vector <User> users;
    XMLFileWithUsers xmlFileWithUsers;
    User giveDataForNewUser();
    bool doesLoginExist(string login);
    //update those methods on UML
    int getIdFromNewUser();
public:
    UserManager(string nameOfFileWithUsers) : xmlFileWithUsers(nameOfFileWithUsers) {
        idLoggedInUser = 0;
        users = xmlFileWithUsers.loadUsersFromXMLFile();
    } ;
    void registerUser();
    int login();
    void changeOfPasswordForLoggedInUser();
    void logout();
    bool isUserLoggedIn();
    void loadUsersFromXMLFile();
    int downloadLoggedInUsersID();

    void displayAllUsers();

};



#endif // USERMANAGER_H
