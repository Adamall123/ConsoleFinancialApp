#include "UserManager.h"


void UserManager::registerUser(){
    cout <<"register user" << endl;
    User user = giveDataForNewUser();

    users.push_back(user);
    xmlFileWithUsers.addUserToXMLFile(user);
    cout << endl << "The account has been made succesfully!" << endl << endl;
    system("pause");
}

////////////////////////////////////////////////////////////////////////Logowanie Uzytkownika ////////////////////////////////////////////////////////////////////////
int UserManager::login() {
    User user;
    string login = "", password = "";

    cout  << "Give login: ";
    cin >> login;

    vector <User>::iterator itr = users.begin();

    while (itr != users.end()) {
        if (itr -> getLogin() == login) {
            cout << "Give password: ";
            for (int amountOfAttemps = 3; amountOfAttemps > 0; amountOfAttemps--) {
                cin >> password;
                if(itr -> getPassword() == password) {
                    cout << endl << "You have logged in" << endl << endl;
                    system("Pause");
                    idLoggedInUser = itr -> getID();
                    return idLoggedInUser;
                }
                system("cls");
                if(amountOfAttemps > 1)
                    cout << "Give password(given wrong password): ";
            }
            cout << "Prove 3 times wrong password" << endl;
            system("Pause");
            return 0;
        }
        itr++;
    }
}

bool UserManager::isUserLoggedIn() {
    if (idLoggedInUser > 0)
        return 1;
    else
        return 0;
}

void UserManager::displayAllUsers(){
    for (int i = 0; i < users.size(); i++){
        cout << users[i].getID() << " .";
        cout << users[i].getName() << endl;
    }
}


User UserManager::giveDataForNewUser() {
    User user;
    user.setID(getIdFromNewUser()) ;
    cout << "Your name: ";
    user.setName(AuxiliaryMethods::loadLine());
    cout << "Your surname: ";
    user.setSurname(AuxiliaryMethods::loadLine());
    do {
        cout  << "Give login: ";
        user.setLogin(AuxiliaryMethods::loadLine())  ;
    } while (doesLoginExist(user.getLogin()) == true);

    cout << "Give password: ";
    user.setPassword(AuxiliaryMethods::loadLine()) ;
    return user;
}


int UserManager::getIdFromNewUser() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getID() + 1;
}

bool UserManager::doesLoginExist(string login) {

    for (int i = 0; i < users.size(); i++) {
        if (users[i].getLogin() == login) {
            cout  << "There is a user with this login name." << endl;
            return true;
        }
    }
    return false;
    /*
    vector <Uzytkownik>::iterator itr = uzytkownicy.begin();
    while (itr != uzytkownicy.end())
    {
        if (itr -> pobierzLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
        else
            itr++;
    }
    return false;
    */
}
