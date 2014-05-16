#ifndef OPERATIONINFO_H
#define OPERATIONINFO_H

#include <iostream>
#include <strings.h>
#include <stdlib.h>
#include <string>
using namespace std;
class operationInfo
{
    public:
        operationInfo();
        operationInfo(string name , bool need , int howMany , bool dir);
        ~operationInfo();
    bool registeronly;
    string operationName;
    int howManyOperand;
    bool directive;

    protected :
    private:

};

#endif // OPERATIONINFO_H
