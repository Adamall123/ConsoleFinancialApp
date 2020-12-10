#include "XMLFileWithUsers.h"


void XMLFileWithUsers::addUserToXMLFile(User user) {

    CMarkup xml;
    //check if file is empty?
    bool fileExists = xml.Load("users.xml");

    if(!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem( "Users" );
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem( "User" );
    xml.IntoElem();
    xml.AddElem( "UserID",  user.getID() );
    xml.AddElem( "Name", user.getName() );
    xml.AddElem( "Surname", user.getSurname() );
    xml.AddElem( "Login", user.getLogin() );
    xml.AddElem( "Password", user.getPassword() );


    xml.Save( "users.xml" );

}

vector <User> XMLFileWithUsers::loadUsersFromXMLFile() {
    User user;
    vector <User> users;
    CMarkup xml;
    bool fileExists = xml.Load("users.xml");
    if(fileExists) {
        xml.ResetPos(); // top of document
        xml.FindElem(); // Users element is root
        xml.IntoElem(); // inside Users
        while ( xml.FindElem("User") ) {
            xml.IntoElem();
            xml.FindElem( "UserID" );
            user.setID(AuxiliaryMethods::convertFromStringToInt(MCD_2PCSZ(xml.GetData())));
            xml.FindElem( "Name");
            user.setName(xml.GetData());
            xml.FindElem( "Surname");
            user.setSurname(xml.GetData());
            xml.FindElem( "Login");
            user.setLogin(xml.GetData());
            xml.FindElem( "Password");
            user.setPassword(xml.GetData());
            users.push_back(user);
            xml.OutOfElem();
        }
    }
    return users;
}
