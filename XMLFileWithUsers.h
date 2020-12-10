#ifndef XMLFILEWITHUSERS_H
#define XMLFILEWITHUSERS_H

#include "XMLTextFile.h"
#include "User.h"
#include "Markup.h"
#include "AuxiliaryMethods.h"
class XMLFileWithUsers : public XMLTextFile{

    public:
    //XMLFileWithUsers();
    XMLFileWithUsers(string nameOfFile): XMLTextFile(nameOfFile) {};
    void addUserToXMLFile(User user);
    void addAllUsersToXMLFile(vector <User> &users);
    vector <User> loadUsersFromXMLFile();

};

#endif // XMLFILEWITHUSERS_H
