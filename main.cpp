#include <iostream>
#include "XMLTextFile.h"
#include "XMLFileWithUsers.h"
using namespace std;

int main()
{
    cout << "Personal Budget - start!" << endl;
    //checking if connected to library correctly
    XMLFileWithUsers test;
    test.addUserToXMLFile();
    return 0;
}
