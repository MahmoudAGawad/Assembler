/*
 * Validator.cpp
 *
 *  Created on: May 14, 2014
 *      Author: mostafa22
 */


#include "Validator.h"
#include <iostream>
#include <strings.h>
#include <stdlib.h>
#include <string>
#include "operationInfo.h"
using namespace std;

Validator :: Validator() {
    // empty constructor
    //string name , bool need , int howMany , bool dir
    operationInfo* firOp = new operationInfo("START" , false , 1 , true);
    operationInfo* secOp = new operationInfo("LDA" , false , 1 , false);
    operationInfo* thiOp = new operationInfo("ADD" , false , 1 , false);
    operationInfo* forOp = new operationInfo("ADDR" , true , 2 , false);

    operationTable.insert("START" , firOp);
    operationTable.insert("LDA" , secOp);
    operationTable.insert("ADD" , thiOp);
    operationTable.insert("ADDR" , forOp);


}

Validator :: Validator(HashTable<int , operationInfo*> opTable) {


}

bool Validator :: checkOpernadSyntax(string operand){

        // if the operation contains label
    if (label != "") {


        // check if name of the label is correct

        int len = label.length();
        bool findchar = false;
        bool invalidchar = false;
        // the first char can't be number , and the label must contain chars
        for( int i = 0 ; i < len ; i++) {

            if( (label[i] - '0') >= 0 && (label[i] - '9') <= 0) {

                if( !i ) {
                    error = "the label name can't start with number";
                    notOk = false;
                    return false;

                }
            }

            // valid chars
            else if(((label[i] -'a') >= 0 && (label[i] - 'z') <= 0) ||
                    ((label[i] -'A') >= 0 && (label[i] - 'Z') <= 0) ) {
                findchar = true;

            } else {
                invalidchar = true;
                notOk = true;
                return false;
            }


        }
        // if true then the label contains char
        if(!findchar){
                error = "the label name must contain char";
                notOk = true;
        }
        else{
           // sympolTable.insert()

        }
        return findchar;

    }
    return true;
}

bool Validator :: checkLabelSyntax(string label) {


    // if the operation contains label
    if (label != "") {

        if( sympolTable.containsKey(label)) {
            // if this label was defined before it can not be redefined
            error = "this label already exist ";
            notOk = true;
            return false;
        }
        // check if name of the label was correct

        int len = label.length();
        bool findchar = false;
        bool invalidchar = false;
        // the first char can't be number , and the label must contain chars
        for( int i = 0 ; i < len ; i++) {

            if( (label[i] - '0') >= 0 && (label[i] - '9') <= 0) {

                if( !i ) {
                    error = "the label name can't start with number";
                    notOk = false;
                    return false;

                }
            }

            // valid chars
            else if(((label[i] -'a') >= 0 && (label[i] - 'z') <= 0) ||
                    ((label[i] -'A') >= 0 && (label[i] - 'Z') <= 0) ) {
                findchar = true;

            } else {
                invalidchar = true;
                notOk = true;
                return false;
            }


        }
        // if true then the label contains char
        if(!findchar){
                error = "the label name must contain char";
                notOk = true;
        }
        else{
           // sympolTable.insert()

        }
        return findchar;

    }
    return true;

}

int Validator :: validHexa(string num) {


    int len = num.length();
    int value = 0;
    int index = 0;

    // check if the num is valid hexa number and return the value else return -1

    for( int i = len - 1  ; i >= 0 ; i--) {

        int pow2 = pow(16 , index);
        int number = 0;

        if( (num[i] - '0') >= 0  && (num[i] - '9') <= 0) {

            number = num[i] - '0';

        } else if((num[i] - 'a') >= 0  && (num[i] - 'f') <= 0) {

            number = num[i] - 'a' + 10;
        } else if((num[i] - 'A') >= 0  && (num[i] - 'F') <= 0) {

            number = num[i] - 'A' + 10;


        }

        // not valid
        else return -1;

        cout<< number<<" , "<<pow2<<endl;
        value +=(number * pow2);

        index++;


    }

    return value;

}


int Validator :: validInt(string num) {


    int len = num.length();
    int value = 0;
    int index = 0;

    // check if the num is valid int number and return the value else return -1

    for( int i = len - 1  ; i >= 0 ; i--) {

        int pow = (10 , index);
        int number = 0;

        if( (num[i] - '0') >= 0  && (num[i] - '9') <= 0) {

            number = num[i] - '0';

        }

        else if( !i && num[i] == '-') {
            value *= -1;
            break;
        }
        // not valid
        else return -10000;

        value +=(number * pow);

        index++;


    }

    return value;


}

bool Validator :: checkDirectiveOpernadSyntax(string operation , string operand) {


    if(operation == "END") {



    }

    else if(operation == "START") {

        // if the operation is start then the operand must be hexa

        int address = validHexa(operand);
        // if the address is -1 then it is not valid

        if( address == -1) {
                error ="not valid hexa number !";
                notOk = true;
            return false;
        }
        return true;
        // the program start is address
    }


    else if( operation == "WORD") {

        // if the operation is word then the operand must be integer

        int value = validInt(operand);

        if( value == -10000) {
                error = "not valid decimal number !";
                notOk = true;
            return false;
        }
        return true;

    }

    else if( operation == "BYTE") {

        // if the operation is byte then the operand could be hexa or strind
        int len = operand.length();

        // if it is hexa
        if(operand[0] == 'X' || operand[0] == 'x') {

            string tempNum = "";
            bool first = true;
            bool endNum = false;
            bool someThingWrong = false;
            for(int i = 1 ; i < len ; i++) {

                if( first && operand[i] == '\'') {

                    first = false;

                } else if( !first && operand[i] == '\'') {

                    endNum = true;
                }

                else if( !first && !endNum) {
                    tempNum +=operand[i];
                } else {
                    someThingWrong = true;
                }

            }

            // not valid instruction
            if(!someThingWrong) {
                int value = validHexa(tempNum);

                //wrong hexa
                if( value == -1) {
                        error = "not valid hexa number";
                        notOk = true;
                    return false;
                }
                return true;
            } else {
                error ="not valid operand !";
                notOk = true;
                return false;
            }

        }

        // if it is string
        else if(operand[0] == 'C' || operand[0] == 'c') {
            string tempNum = "";
            bool first = true;
            bool endNum = false;
            bool someThingWrong = false;
            for(int i = 1 ; i < len ; i++) {

                if( first && operand[i] == '\'') {

                    first = false;

                } else if( !first && operand[i] == '\'') {

                    endNum = true;
                }

                else if( !first && !endNum) {
                    tempNum +=operand[i];
                } else {
                    someThingWrong = true;
                }

            }

            if(!someThingWrong){
                                error = "not valid operand ";

            }
            else return false;


        }
        // does't start with (X) or with (C)
        else {
            // wrong instruction
                                error = "not valid operand ";
        }



    }


    else if( operation == "RESW" || operation == "RESB"){

        // the operand must be a valid decimal number
        int sizeOfArray = validInt(operand);

        // not valid size
        if( sizeOfArray == -10000){
            notOk = true;
            error = "not valid decimal number !";
            return false;
        }
        return true;
    }
}

bool Validator :: split(string operand , string reg[]){

    // split the operand

    int len = operand.length();
     int comma = 0;
     string load = "";
     for(int i = 0 ; i < len ; i++){

        if(operand[i] == ','){
            if(!comma && i != 0&& i+1 != len){
                    // first comma
                comma ++;
            }
            else{
                    // can't be more than one comma
                notOk = true;
                error = "extra chars at the end of the stat !";
                return false;
            }
            reg[0] = load;
            load = "";
        }

        else{
            load += operand[i];
        }
     }

//     if(load == ""){
//        notOk = true;
//        error ="unvalid operand !";
//        return false;
//     }
     reg[1]= load;
     return true;

}

void Validator :: checkSyntax(string label , string operation , string operand) {


    if(!checkLabelSyntax(label)) {
        return;
    }

    if( operationTable.containsKey(operation)) {

        // if the operation is corect

        operationInfo* opTemp = operationTable.get(operation);
        int howManyoperand = opTemp->howManyOperand;
        bool registerInfo = opTemp->registeronly;
        bool dirctive = opTemp->directive;

        if( dirctive ) {
            // check if the operand is correct
            if(!checkDirectiveOpernadSyntax(operation , operand)){
                notOk = true;
            }
            else return;

        }

        else {
            // then the operation is not dirctive
            // if the operation needs 2 operand then the operands must be registers
            if( howManyoperand == 2) {
                // check if the operand is register

                string reg[2];
                reg[0]="";
                reg[1]="";
                if(split(operand , reg)){
                    //if reg[0] is not aregister or reg[1]
                    if(!operationTable.containsKey(reg[0]) || !operationTable.containsKey(reg[1])){
                        notOk = true;
                        error = "not valid register !";
                        return;
                    }
                }
                else{
                        //the instruction is correct
                    return ;
                }

                cout<<"needs two register\n";
            }


            else if( howManyoperand == 0) {
                // no operand

                // this operation does not need any operand so the operand field should be empty

                if(operand != "") {

                    if(operand == "RSUB") {
                        // WARNNING
                        error = "warning this operation does not need any operand the operand will be ignored .";

                        return;

                    }

                    else {
                            notOk=true;
                        error = "error this operation does not need any operand";
                        return;
                    }
                }





            }
            // the operation need 1 opernd
            else {

                // if the operation needs the operand to be register

                if(registerInfo) {

                    // check if the operand is a valid register

                    if(!operationTable.containsKey(operand)){

                        // the operand is not a register
                        notOk = true;
                        error = "invalid register address";
                        return;

                    }
                    cout<<"needs one register\n";
                    return;

                }
                // if the operation does't need register
                else {
                    cout<<"does not need any register\n";
                    // then the operand could be name , number or index
                    string reg[2];
                    reg[0]="";
                    reg[1]="";
                    if(!split(operand , reg)){
                        return;
                    }

                    // if their wax a comma , then the reg[1] must contain (X, index mode) and
                    // reg[0] must not start with (#,@)

                    if( reg[1] != ""){

                        if(reg[1] != "X"){
                            notOk = true;
                            error = "invalid index mode !";
                            return;
                        }
                        else if( reg[0] == "#" || reg[0] ="@" ){

                            notOk = true;
                            error = "invalid index mode !";
                            return;
                        }
                        else if(checkOpernadSyntax){



                        }


                    }

                }

            }



        }


    }

    // the operation is not valid
    notOk = true;
    error = "invalid operation !";
}






