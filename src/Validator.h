   /*
 * Validator.h
 *
 *  Created on: May 14, 2014
 *      Author: msotafa22
 */

#ifndef VALIDATOR_H
#define VALIDATOR_H

#include "HashTable.cpp"
#include <iostream>
#include <strings.h>
#include <stdlib.h>
#include <string>

using namespace std;
class Validator{

public :
    Validator( HashTable<int , int> opTable );

    Validator();  //  empty costructor
    ~Validator(); // destructor

    void checkSyntax(string label , string operation , string operand); // check the syntax of the operation
    bool checkLabelSyntax(string label); // to check if the label is correct
    bool checkOpernadSyntax(string operand);
    bool checkDirectiveOpernadSyntax(string operation  , string operand);
    int validHexa(string num); // to check if the num is correct hexa if true return the value ,else return -1
    int validInt(string num); // to check if the num is correct integer
    bool checkValid();
    string getError();


protected :
    HashTable<string , int> sympolTable;    // the table containing all the sympols
    HashTable<string , int> operationTable; // the table containing all the informathion about the operation
    string error ;                          // the error message
private:


};


#endif /* VALIDATOR_H_ */
