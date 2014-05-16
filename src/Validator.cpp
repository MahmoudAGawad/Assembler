/*
 * Validator.cpp
 *
 *  Created on: May 14, 2014
 *      Author: mostafa22
 */

//#include "operationInfo.h"

#include "Validator.h"
#include "operationInfo.h"


Validator :: Validator(){
  // empty constructor
}

Validator :: Validator(HashTable<int , int> opTable){

    operationInfo x ;
//operationTable = opTable;

}

bool Validator :: checkLabelSyntax(string label){


    // if the operation contains label
    if (label != ""){

            if( sympolTable.containsKey(label)){
            // if this label was defined before it can not be redefined
                error = "this label already exist ";
                return false;
            }
            // check if name of the label was correct

            int len = label.length();
            bool findchar = false;
            bool invalidchar = false;
            // the first char can't be number , and the label must contain chars
            for( int i = 0 ; i < len ; i++){

                if( (label[i] - '0') >= 0 && (label[i] - '0') <= 9){

                    if( !i ){
                    error = "the label name can't start with numbre";

                    return false;

                    }
                }

                    // valid chars
                else if(((label[i] -'a') >= 0 && (label[i] - 'z') <= 0) ||
                        ((label[i] -'A') >= 0 && (label[i] - 'Z') <= 0) ){
                        findchar = true;

                }
                else{
                    invalidchar = true;
                    return false;
                }


            }
            // if true then the label contains char
            if(!findchar)error = "the label name must contain char";

            return findchar;

    }
    return true;

}

int Validator :: validHexa(string num){


    int len = num.length();
    int value = 0;
    int index = 0;

    // check if the num is valid hexa number and return the value else return -1

    for( int i = len - 1  ; i >= 0 ; i--){

            int pow = (16 , index);
            int number = 0;

        if( (num[i] - '0') >= 0  && (num[i] - '9') <= 0){

             number = num[i] - '0';

        }
        else if((num[i] - 'a') >= 0  && (num[i] - 'f') <= 0){

            number = num[i] - 'a' + 10;
        }
        else if((num[i] - 'A') >= 0  && (num[i] - 'F') <= 0){

            number = num[i] - 'A' + 10;


        }

        // not valid
        else return -1;
            value +=(number * pow);

            index++;


    }

     return value;

}


int Validator :: validInt(string num){


    int len = num.length();
    int value = 0;
    int index = 0;

    // check if the num is valid int number and return the value else return -1

    for( int i = len - 1  ; i >= 0 ; i--){

            int pow = (10 , index);
            int number = 0;

        if( (num[i] - '0') >= 0  && (num[i] - '9') <= 0){

             number = num[i] - '0';

        }

        else if( !i && num[i] == '-'){
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

bool Validator :: checkDirectiveOpernadSyntax(string operation , string operand){


    if(operation == "END"){



    }

    if(operation == "START"){

        // if the operation is start then the operand must be hexa

        int address = validHexa(operand);
        // if the address is -1 then it is not valid

        if( address == -1){
            return false;
        }

        // the program start is address
    }


    else if( operation == "WORD"){

        // if the operation is word then the operand must be integer

        int value = validInt(operand);

        if( value == -10000){
            return false;
        }

    }

    else if( operation == "BYTE"){

        // if the operation is byte then the operand could be hexa or strind
        int len = operand.length();

        // if it is hexa
        if(operand[0] == 'X' || operand[0] == 'x'){

            string tempNum = "";
            bool first = true;
            bool endNum = false;
            bool someThingWrong = false;
            for(int i = 1 ; i < len ; i++){

                if( first && operand[i] == '\''){

                    first = false;

                }
                else if( !first && operand[i] == '\''){

                    endNum = true;
                }

                else if( !first && !endNum){
                    tempNum +=operand[i];
                }
                else{
                    someThingWrong = true;
                }

            }

            // not valid instruction
            if(!someThingWrong){
            int value = validHexa(tempNum);
            //wrong hexa
            if( value == -1){
            return false;
            }
            }
            else return false;


        }

        // if it is string
        else if(operand[0] == 'C' || operand[0] == 'c'){
            string tempNum = "";
            bool first = true;
            bool endNum = false;
            bool someThingWrong = false;
            for(int i = 1 ; i < len ; i++){

                if( first && operand[i] == '\''){

                    first = false;

                }
                else if( !first && operand[i] == '\''){

                    endNum = true;
                }

                else if( !first && !endNum){
                    tempNum +=operand[i];
                }
                else{
                    someThingWrong = true;
                }

            }

            if(!someThingWrong)
            int x = 0;
            else return false;


        }
        else{
            // wrong instruction
        }

    }
}


void Validator :: checkSyntax(string label , string operation , string operand){


    if(!checkLabelSyntax(label)){
        return;
    }

    if( operationTable.containsKey(operation)){

        // if the operation is corect

        //operationInfo* t = new operationInfo();
        int howManyoperand = 0;
        bool registerInfo = 0;
        bool dirctive = 0;

        if( dirctive ){
                // check if the operand is correct
            checkDirectiveOpernadSyntax(operation , operand);
        }

        else{
            // then the operation is not dirctive
            // if the operation needs 2 operand then the operands must be registers
            if( howManyoperand == 2){
                // check if the operand is register
            }


            else if( howManyoperand == 0){
                // no operand

            // this operation does not need any operand so the operand field should be empty

            if(operand != ""){

                if(operand == "RSUB"){
                    // WARNNING
                    error = "warning this operation does not need any operand the operand will be ignored .";

                    return;

                }

                else{
                    error = "error this operation does not need any operand";
                    return;
                }
            }





           }
           // the operation need 1 opernd
           else{

            // if the operation needs the operand to be register

            if(registerInfo){

                // check if the operand is a valid register

            }
            // if the operation does't need register
            else{


            }

           }



        }


    }

    // the operation is not valid
    error = "invalid operation !";
}






