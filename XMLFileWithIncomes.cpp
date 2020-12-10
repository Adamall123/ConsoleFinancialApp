#include "XMLFileWithIncomes.h"

void XMLFileWithIncomes::addIncomeToXMLFile(Income income){
     CMarkup xml;


    bool fileExists = xml.Load("incomes.xml");

    if(!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem( "Incomes" );
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem( "Income" );
    xml.IntoElem();
    xml.AddElem( "IncomeID", income.getIncomeID() );
    xml.AddElem( "UserID",   income.getUserId() ); //from string to double
    xml.AddElem( "Date", income.getDate() ); //here it must be changed again with pattern from int to string with '-'
    xml.AddElem( "Item", income.getItem() );
    xml.AddElem( "Amount", AuxiliaryMethods::convertFromFloatToString(income.getAmount()) );
    xml.Save( "incomes.xml" );
}

vector <Income> XMLFileWithIncomes::loadIncomesFromXMLFile() {
    Income income;
    vector <Income> incomes;
    CMarkup xml;
    bool fileExists = xml.Load("incomes.xml");
    if(fileExists) {
        xml.ResetPos(); // top of document
        xml.FindElem(); // incomes element is root
        xml.IntoElem(); // inside incomes
        while ( xml.FindElem("Income") ) {
            xml.IntoElem();
            xml.FindElem( "IncomeID" );
            income.setUserID(AuxiliaryMethods::convertFromStringToInt(MCD_2PCSZ(xml.GetData())));
            xml.FindElem( "UserID");
            income.setIncomeID(AuxiliaryMethods::convertFromStringToInt(MCD_2PCSZ(xml.GetData())));
            xml.FindElem( "Date"); //changing from string to int without '-'
            income.setDate(AuxiliaryMethods::convertFromStringToInt(MCD_2PCSZ(xml.GetData())));
            xml.FindElem( "Item");
            income.setItem(xml.GetData());
            xml.FindElem( "Amount");
            income.setAmount(AuxiliaryMethods::convertFromStringToInt(MCD_2PCSZ(xml.GetData())));
            incomes.push_back(income);
            xml.OutOfElem();
        }
    }
    return incomes;
}

int XMLFileWithIncomes::returnLastIncomeId(){
    Income income;
    CMarkup xml;
    bool fileExists = xml.Load("incomes.xml");
    if(fileExists){
         xml.ResetPos(); // top of document
        xml.FindElem(); // incomes element is root
        xml.IntoElem(); // inside incomes
        while ( xml.FindElem("Income") ) {
            xml.IntoElem();
            xml.FindElem( "IncomeID" );
            idFromLastIncome = AuxiliaryMethods::convertFromStringToInt(MCD_2PCSZ(xml.GetData())); //after a while, when on last element than assign
            xml.OutOfElem();
        }
    return idFromLastIncome;
    }
    else return 0;
}
