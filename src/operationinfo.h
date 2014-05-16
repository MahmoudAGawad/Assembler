#ifndef OPERATIONINFO_H
#define OPERATIONINFO_H

#include <iostream>
#include <strings.h>
using namespace std;
class operationInfo
{
    public:
        operationInfo();
        operationInfo(string name , bool need , int howMany);
        ~operationInfo();
    protected:
    bool registeronly;
    string operationName;
    int howManyOperand;
    bool directive;
};

#endif // OPERATIONINFO_H
