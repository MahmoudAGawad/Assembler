   /*
 * Validator.h
 *
 *  Created on: May 14, 2014
 *      Author: msotafa22
 */

#ifndef VALIDATOR_H
#define VALIDATOR_H

#include "includes.h"
#include "operationInfo.h"
#include "HashTable.cpp"
#include "labelInfo.h"
using namespace std;
class Validator{

public :
    Validator( HashTable<string , operationInfo> opTable );

    Validator();  //  empty costructor
    ~Validator(); // destructor

    void validateSyntax(string label , string operation , string operand);
    bool isValid();
    string getError();
    string getAddress();
    HashTable<string , labelInfo> getSympolTable();
protected:

    void checkSyntax(string label , string operation , string operand); // check the syntax of the operation
    bool checkLiteralSyntax(string operation ,string operand);
    bool checkLabelSyntax(string label); // to check if the label is correct
    bool checkOpernadSyntax(string operand);
    bool checkDirectiveOpernadSyntax( string operation , string operand);
    bool isAbsoluteExpression(string expr);
    int validHexa(string num); // to check if the num is correct hexa if true return the value ,else return -1
    int validInt(string num); // to check if the num is correct integer
    bool split(string operand , string reg[]);
    string intToHexa(int num);
    void kill();

    bool findStart;
    bool notOk ;
    bool LTORG;
    bool isEQU ;
    bool isAbsolute;
    int startAddress ;
    int prevAddress ;
    int format ;
    static const int maxSpace = 1048576 ;
    HashTable<string , labelInfo> sympolTable;    // the table containing all the sympols
    HashTable<string , operationInfo> operationTable; // the table containing all the informathion about the operation
    HashTable<string , int> tempLiteralTable ;
    HashTable<string , string>literalTable;
    string error ;                          // the error message
private:


};


#endif /* VALIDATOR_H_ */
