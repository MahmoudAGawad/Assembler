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
        operationInfo(int operands, string format, string opCode, string register_);
        ~operationInfo();


    protected :
    private:
        int operands;
        string format;
        string opCode;
        bool regist;

};

#endif // OPERATIONINFO_H
