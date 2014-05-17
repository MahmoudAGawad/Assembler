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
        int getOperands();
        bool isRegisiterOnly();
        bool isDirective();
        string getFormat();
        string getOpCode();



    protected :
    private:
        int operands;
        string format;
        string opCode;
        bool regist, directive;

};

#endif // OPERATIONINFO_H
