#include "XMLTextFile.h"


string XMLTextFile::disposeOfDashesInDate(string strDate) {
    string date="";
    for (int i = 0; i < strDate.size(); i++) {
        if(strDate[i] != '-')
            date+= strDate[i];
    }
    return date;
}

string XMLTextFile::addDashesInDate(string date) {
    string year ="", month ="", day="";
    for (int i = 0; i < date.size(); i++) {
        if(i < 4)
            year += date[i];
        else if(i < 6)
            month += date[i];
        else if (i < 8)
            day += date[i];
    }
    return year + '-' + month + '-' + day;
}

