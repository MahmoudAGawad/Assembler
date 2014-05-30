/*
 * ObjectCode.h
 *
 *  Created on: May 30, 2014
 *      Author: Mahmoud Saleh <3 Waleed Adel
 */

#ifndef OBJECTCODE_H_
#define OBJECTCODE_H_

#include "Validator.h"
#include <string>
#include <vector>
#include "GeneralTasks.h"
#include <strings.h>
#include <string>
#include "stdio.h"
#include "stdlib.h"
#include <algorithm>
class ObjectCode{
public:
    int n,i,x,b,p,e;

    ObjectCode(HashTable<string,operationInfo> *optbl, HashTable<string,string> *symbtbl, HashTable<string,string> *littbl);

    string getObjectCode(string operation, string operand, int pc);
    string getError();
    bool isValid();
    void writeObjectFile();

private:
    HashTable<string,operationInfo> *operationTable;
    HashTable<string,string> *symbolTable;
    HashTable<string,string> *literalTable;
    string error;
    bool valid;
    vector<string> codes;
    vector<string> modify;

    string operandProccessing(string operand, int pc);
    void operationProcessing(string operation);
};


#endif /* OBJECTCODE_H_ */
