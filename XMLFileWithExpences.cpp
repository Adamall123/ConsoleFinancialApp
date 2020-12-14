#include "XMLFileWithExpences.h"

vector <Expence> XMLFileWithExpences::loadExpencesFromXMLFile() {
    Expence expence;
    string strDate="";
    vector <Expence> expences;
    CMarkup xml;
    bool fileExists = xml.Load("expences.xml");
    if(fileExists) {
        xml.ResetPos(); // top of document
        xml.FindElem(); // incomes element is root
        xml.IntoElem(); // inside incomes
        while ( xml.FindElem("Expence") ) {
            xml.IntoElem();
            xml.FindElem( "ExpenceID" );
            expence.setUserID(AuxiliaryMethods::convertFromStringToInt(MCD_2PCSZ(xml.GetData())));
            xml.FindElem( "UserID");
            expence.setExpenceID(AuxiliaryMethods::convertFromStringToInt(MCD_2PCSZ(xml.GetData())));
            xml.FindElem( "Date"); //changing from string to int without '-'
            strDate = MCD_2PCSZ(xml.GetData());
            expence.setDate(AuxiliaryMethods::convertFromStringToInt(AuxiliaryMethods::disposeOfDashesInDate(strDate)));
            xml.FindElem( "Item");
            expence.setItem(xml.GetData());
            xml.FindElem( "Amount");
            expence.setAmount(AuxiliaryMethods::convertFromStringToFloat(MCD_2PCSZ(xml.GetData())));
            expences.push_back(expence);
            xml.OutOfElem();
        }
    }
    return expences;
}


void XMLFileWithExpences::addExpenceToXMLFile(Expence expence){
     CMarkup xml;

    bool fileExists = xml.Load("expences.xml");

    if(!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem( "Expences" );
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem( "Expence" );
    xml.IntoElem();
    xml.AddElem( "ExpenceID", expence.getExpenceID() );
    xml.AddElem( "UserID",   expence.getUserId() );
    string date = AuxiliaryMethods::convertFromIntToString(expence.getDate());
    xml.AddElem( "Date", AuxiliaryMethods::addDashesInDate(date) );
    xml.AddElem( "Item", expence.getItem() );
    xml.AddElem( "Amount", AuxiliaryMethods::convertFromFloatToString(expence.getAmount()) );
    xml.Save( "expences.xml" );
}

int XMLFileWithExpences::returnLastExpenceId(){
    Expence expence;
    CMarkup xml;
    bool fileExists = xml.Load("expences.xml");
    if(fileExists){
         xml.ResetPos(); // top of document
        xml.FindElem(); // incomes element is root
        xml.IntoElem(); // inside incomes
        while ( xml.FindElem("Expence") ) {
            xml.IntoElem();
            xml.FindElem( "ExpenceID" );
            idFromLastExpence = AuxiliaryMethods::convertFromStringToInt(MCD_2PCSZ(xml.GetData())); //after a while, when on last element than assign
            xml.OutOfElem();
        }
    return idFromLastExpence;
    }
    else return 0;
}
