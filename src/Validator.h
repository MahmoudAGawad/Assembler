/*
 * Validator.h
 *
 *  Created on: May 14, 2014
 *      Author: msotafa22
 */

#ifndef VALIDATOR_H_
#define VALIDATOR_H_

class Validator{

public :
    Validator(HashTable<string , operationInfo> opTable);
    Validator();  //  empty costructor
    ~Validator(); // destructor

    void checkSyntax(string label , string operation , string operand); // check the syntax of the operation
    bool checkValid();
    string getError();


protected :
    HashTable<string , int> sympolTable; // the table containing all the sympols
    HashTable<string , operationInfo> operationTable; // the table containing all the informathion about the operation
    string error ;                       // the error message


};


#endif /* VALIDATOR_H_ */
