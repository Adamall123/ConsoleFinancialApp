#ifndef XMLTEXTFILE_H
#define XMLTEXTFILE_H

#include <vector>
#include <iostream>
using namespace std;

class XMLTextFile{
    const string NAME_OF_FILE;
    bool isFileEmpty();
    string downloadNameFile();
public:
    XMLTextFile(string nameOfFile) : NAME_OF_FILE(nameOfFile) {}
};


#endif // XMLTEXTFILE_H
