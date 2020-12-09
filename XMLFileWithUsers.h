#ifndef XMLFILEWITHUSERS_H
#define XMLFILEWITHUSERS_H

#include "XMLTextFile.h"
#include "User.h"
#include "Markup.h"
class XMLFileWithUsers : public XMLTextFile{

    public:
    //XMLFileWithUsers();
    void addUserToXMLFile();
    void addAllUsersToXMLFile();
    vector <User> loadUsersFromXMLFile();

};

#endif // XMLFILEWITHUSERS_H
