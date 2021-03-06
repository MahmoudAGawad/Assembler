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
#include <math.h>
#include <algorithm>
#include "GeneralTasks.h"
using namespace std;

Validator :: Validator() {
    // empty constructor
    //string name , bool need , int howMany , bool dir
     notOk = LTORG =isAbsolute=isAbsolute==false;
     startAddress = -1;
     prevAddress = -1;
     format = 0;
     findStart = false;
     isEQU = false;




}

Validator :: Validator(HashTable<string , operationInfo> opTable) {

    operationTable = opTable;
    notOk = LTORG = isAbsolute =false;
    startAddress = -1;
     prevAddress = -1;
     format = 0;
    findStart = false;


}

string Validator :: getAddress(){

    string curAddress = "";
    if(startAddress == -1){
//        notOk = true;
//        error = "invalid start of the program";
        startAddress = 0;
        prevAddress = 0;
        startAddress += format;
        return "0000";
    }
    else if(startAddress > maxSpace){
            notOk = true;
            error = "over flow";
        if(prevAddress == -1){
            prevAddress = 0;
        }
        curAddress = intToHexa(prevAddress);
        return curAddress;

    }

    else if(notOk){
       // return the address and don't add any thing
       if(prevAddress == -1){
        curAddress = intToHexa(startAddress);
       }
       else
       curAddress = intToHexa(prevAddress);
    }
    else{
        //return the address and update the address
        curAddress = intToHexa(startAddress);
        prevAddress = startAddress;
       startAddress += format;
    }
     return curAddress;

}


string Validator :: intToHexa(int num){
    if(num == 0)return "0000";
    string result = "";
    string returnResult = "";
    while(num > 0){

        int mod = num % 16;
        num /= 16;
        if(mod < 10){
            result +=('0'+mod);
        }
        else{
            result +=('A'+(mod-10));
        }

    }
    for(int i = result.length()-1 ; i >=0 ; i--){
        returnResult += result[i];
    }
    return returnResult;

}

bool Validator :: checkOpernadSyntax(string operand){

        // if the operation contains label
        if(operand == "*") return true;
    if (operand != "") {


        // check if name of the label is correct

        int len = operand.length();
        bool findchar = false;
        bool invalidchar = false;
        bool startWithDigit = false;
        // the first char can't be number , and the label must contain chars
        for( int i = 0 ; i < len ; i++) {

            if( (operand[i] - '0') >= 0 && (operand[i] - '9') <= 0) {

                if( !i ) {
                    startWithDigit = true;

                }
            }

            // valid chars
            else if(((operand[i] -'a') >= 0 && (operand[i] - 'z') <= 0) ||
                    ((operand[i] -'A') >= 0 && (operand[i] - 'Z') <= 0) ) {
                findchar = true;

            } else {
                invalidchar = true;
                notOk = true;
                error ="invalid char";
                return false;
            }


        }
        // if true then the label contains char
        if(findchar && startWithDigit){
                error = "the label name can't start with digit";
                notOk = true;
                return false;
        }
        else{
           // sympolTable.insert()

        }
        return true;

    }
    return true;
}

bool Validator :: checkLabelSyntax(string label) {


    // if the operation contains label
    if (label != "") {

        if( sympolTable.containsKey(label) || operationTable.containsKey(label)) {
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
                    notOk = true;
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
//        cout<<pow2<<endl;
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

       // cout<< number<<" , "<<pow2<<endl;
        value +=(number * pow2);

        index++;


    }

    return value;

}


int Validator :: validInt(string num) {

    if(num == "*") return startAddress;
    int len = num.length();
    int value = 0;
    int index = 0;

    // check if the num is valid int number and return the value else return -1

    for( int i = len - 1  ; i >= 0 ; i--) {

        int pow2 = pow(10 , index);
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

        value +=(number * pow2);

        index++;


    }

    return value;


}


bool Validator :: checkLiteralSyntax(string operation ,string operand){


        string word = operand;
        // to store the (C or X or W)
        string type = "";
        //to store the value without ( ' or x or c)
        string oper = "";
        bool findColon1 = false , findColon2 = false , wrong = false , alreadyFounndColon = false;

        for(int i = 1 ; i < word.length() ; i++){


             if(!findColon1 && word[i] =='\''){
                alreadyFounndColon = true;
                findColon1 = true;
            }
            else if(!findColon2 && word[i] =='\''){
                findColon2 = true;
            }

            else if(findColon1 && !findColon2){
                oper += word[i];
            }

            else if(!findColon1 && !findColon2){
                if(alreadyFounndColon)wrong = true;

                type += word[i];
            }




        }

        if(wrong || !alreadyFounndColon || !findColon2){
            notOk = true;
            error = "not valid literal !";
            return false;
        }

        if(tempLiteralTable.containsKey(operand) && oper !="*" ){
            return true;
        }

        // if it is empty or W then it should be valid decimal number
        else if(type == "" || type == "w" || type == "W"){
            int value = validInt(oper);

            if(value == -10000){
                notOk = true;
                error = "not valid decimal number !";
                return false;
            }
            // if it is valid put it in the literal table
            tempLiteralTable.insert(operand , 3);



        }
        // if it is C then it is a string
        else if(type == "C" || type == "c"){
            if((operation == "LDCH" && oper.length() != 1)|| oper.length()!=3){
                notOk = true;
                error = "illegal operand !";
                return false;
            }

            // then it is true but the format
           // string form = General::intToString( oper.length());

            tempLiteralTable.insert(operand , oper.length());
        }

        else if(type == "X" || type == "x" ){
            // if it is X then it is hexa number
            int value = validHexa(oper);
            if(value == -1){
                // not valid hexa
                notOk = true;
                error = "not valid hexa number !";
                return false;
            }
          //  string form = General::intToString(oper.length() / 2);
            tempLiteralTable.insert(operand , oper.length() / 2);

        }
        else {
            notOk = true;
            error = "unknown type !";
            return false;
        }




}

bool Validator :: checkDirectiveOpernadSyntax(string operation , string operand) {


    if(operation == "END") {

        if(tempLiteralTable.size() != 0){
        LTORG = true;
        literalTable.init();

        tempLiteralTable.iterator();
        while(tempLiteralTable.hasNext()){

            Entry<string , int>*entry = tempLiteralTable.next();
            string literal = entry->getKey();
            format = entry->getValue();
            string add = getAddress();
            literalTable.insert(literal , add);


        }
        tempLiteralTable.init();

        }

        return true;
    }

    else if(operation == "START") {
            findStart = true;
        if(startAddress != -1){
            notOk = true;
            error = "2 start";
            return false;
        }
        format = 0;
        // if the operation is start then the operand must be hexa
        if(operand == ""){
            startAddress = 0;
            return true;
        }
        int address = validHexa(operand);
        // if the address is -1 then it is not valid

        if( address == -1 || address > maxSpace) {
                error ="not valid hexa number !";
                notOk = true;
            return false;
        }
        startAddress = address;
        return true;
        // the program start is address
    }


    else if( operation == "WORD") {

        // if the operation is word then the operand must be integer

        int value = validInt(operand);
        format  = 0;
        if( value == -10000) {
                error = "not valid decimal number !";
                notOk = true;
            return false;
        }
        if(operand.length() >= 7){
            notOk = true;
            error = "extra chars at the end of the statment !";
            return false;
        }
        format = 3 ;
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
                if(tempNum.length() % 2 != 0 ){
                    notOk = true;
                    error = "odd number of digit";
                    return false;
                }

                format = tempNum.length() / 2;
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
                    format = tempNum.length();
                return true;

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
//        if(operand.length() >= 7){
//            notO
//        }

        if(operation == "RESW")format = 3* sizeOfArray;
        else format = sizeOfArray;
        return true;
    }

    //if it is EQU then the label will be added the symbol table with the given value
    else if(operation == "EQU"){
        format = 0;
        isAbsoluteExpression(operand);
        isEQU = true;
                return true;


    }


    else if(operation == "ORG"){

        isAbsoluteExpression(operand);
        if(notOk)return false;
        prevAddress = -1;
        //update the address with the value of the operand

        startAddress = 0;
        return true;

    }


    else if(operation == "LTORG"){
        LTORG = true;
       // literalTable.kill();
        literalTable.init();
        tempLiteralTable.iterator();
        while(tempLiteralTable.hasNext()){

            Entry<string , int>*entry = tempLiteralTable.next();
            string literal = entry->getKey();
            format = entry->getValue();
            string add = getAddress();
            literalTable.insert(literal , add);


        }
        tempLiteralTable.init();
        return true;


    }
    return false;
}

bool Validator :: isAbsoluteExpression(string operand){

      vector<string> splitExpr = General::parseExpression(operand , startAddress);
        int numberOfPostive = 0 , numberOfNegative = 0;


        // if the operand is valid then put it in the Symbol table
        for(int i = 0 ; i < splitExpr.size() ;i++){

            string tmp = splitExpr[i];

            if(tmp=="+" || tmp=="-" ||tmp=="*" || tmp=="/"){

                continue;

            }
            int value = validInt(tmp);

            if(value == -10000 &&!sympolTable.containsKey(tmp)){
                notOk = true;
                error = tmp+" was not defined !";
                return false;
            }
            else if(sympolTable.containsKey(tmp)){
                labelInfo label = sympolTable.get(tmp);
                if(!label.isAbsolute()&&(i == 0 || splitExpr[i-1] == "+")){
                    numberOfPostive++;
                }
                else if(!label.isAbsolute()&&(splitExpr[i-1] == "-")){
                    numberOfNegative++;
                }
                else if(!label.isAbsolute()&&(splitExpr[i-1] == "/" || splitExpr[i-1] == "*")){
                    notOk = true;
                    error = "invalid expression !";
                    return false;
                }
            }

        }
        // static expression , when every relative part can be paired with another relative part
        if(numberOfNegative == numberOfPostive){
            isAbsolute = true;
        }
        else if(numberOfPostive == numberOfNegative + 1){
            isAbsolute = false;
        }
        else{
            isAbsolute = false;
            notOk = true;
            error = "invalid expression !";
            return false;
        }

}


bool Validator :: split(string operand , string reg[]){

    // split the operand
//    cout <<operand <<endl;
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
//            cout<<"load : "<<load<<endl;
        }
     }

//     if(load == ""){
//        notOk = true;
//        error ="unvalid operand !";
//        return false;
//     }
    if(comma == 1)
        {
            reg[1]= load;

        }

     else reg[0]=load;
     //if(com)
     return true;

}

void Validator :: checkSyntax(string label , string operation , string operand) {


    notOk = isEQU = LTORG = false;
    error = "";
    bool formatFour = false;
    if(!checkLabelSyntax(label)) {
        return;
    }

    if(operation[0] == '+'){
        // it's format 4
        string tempOperation = "";
        for(int i = 1; i < operation.length() ; i++ ){
            tempOperation += operation[i];
        }
        formatFour = true;
        operation = tempOperation;
    }
//            cout<<endl;
//            cout<<operationTable.containsKey(operation)<<" 8 ";
             //   cout <<" " <<operation;

   transform(operation.begin(), operation.end(), operation.begin(), ::toupper);
    if( operationTable.containsKey(operation)) {


        // if the operation is corect

        operationInfo opTemp = operationTable.get(operation);
        int howManyoperand = opTemp.getOperands();
        bool registerInfo = opTemp.isRegisiterOnly();
        bool dirctive = opTemp.isDirective();
        string opFormat = opTemp.getFormat();
        //bool isReg = opTemp.isRegister();
        if(opFormat == "1"){
            format = 1;
        }

        if(opFormat == "2"){
            format = 2;
        }
        if(opFormat == "3/4"){
                if(formatFour)
                  format = 4;

                else format = 3;
        }
        if(formatFour && (format == 1 || format == 2)){
            notOk = true;
            error = "wrong index mode";
            return;
        }
        if( dirctive ) {
            // check if the operand is correct
            cout<<operation<<"####"<<endl;
            if(!checkDirectiveOpernadSyntax(operation , operand)){
                notOk = true;
                return;
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

                    operationInfo tempReg1 = operationTable.get(reg[0]);
                    operationInfo tempReg2 = operationTable.get(reg[1]);
                    if(!tempReg1.isRegister() || !tempReg2.isRegister() ){
                        notOk = true;
                        error = "not valid register !";
                        return;
                    }
                    else {
                        return;
                    }
                }
                else{
                        //the instruction is correct
                    notOk = true;
                    //error = "invalid"
                    return ;
                }

              //  cout<<"needs two register\n";
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
                else{
                    return;
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
                   // cout<<"needs one register\n";
                    return;

                }
                // if the operation does't need register
                else {
                   // cout<<"does not need any register\n";

                    // then the operand could be name , number or index
                    string reg[2];
                    reg[0]="";
                    reg[1]="";

                    if(!split(operand , reg)){
                        return;
                    }
//                    cout<<"(0)"<<reg[0]<<"(1)"<<reg[1]<<endl;
                    // if their wax a comma , then the reg[1] must contain (X, index mode) and
                    // reg[0] must not start with (#,@)

                    if( reg[1] != ""){
//                        cout<<"yes here"<<endl;

                        if(reg[1] != "X"){
//                            cout<<"yes here X"<<endl;

                            notOk = true;
                            error = "invalid index mode !";
                            return;
                        }
                        else if( reg[0][0] == '#' || reg[0][0] =='@' ){

                            notOk = true;
                            error = "invalid index mode !";
                            return;
                        }
                        else if(!checkOpernadSyntax(reg[0])){
                                notOk = true;
                                error = "invalid operand name !";
                                return;


                        }
                        else{
                                // correct instrucion
                            return;
                        }


                    }

                    else{
                        // the reg[0] can start with # or @
//                        cout<<"yes from else"<<endl;
                        if(reg[0][0] == '#' || reg[0][0] == '@'){

                            // one of the index modes
                            string temp = "";
                            string tempreg = reg[0];
                            bool allDigits = true;
                            for(int i = 1 ; i < tempreg.length() ; i++){

                                temp += tempreg[i];
                                if((tempreg[i] -'g' >= 0 && tempreg[i]-'z' <=0)||
                                   (tempreg[i] -'G' >= 0 && tempreg[i]-'Z' <=0)){
                                    allDigits = false;
                                }

                            }
                            if(! checkOpernadSyntax(temp)){
                                return;
                            }
                            else if(allDigits){

                                if(temp.length() >= 7){
                                    notOk = true;
                                    error = "extra chars at the end of the statment";
                                }
                                return;
                            }
                            else return;

                        }
                        // if it starts with (=) then it is literal
                        else if(reg[0][0] == '='){
                               checkLiteralSyntax(operation ,reg[0]);
                            return;



                        }


                        else{
//                                cout<<"yes from else"<<endl;

                            checkOpernadSyntax(reg[0]);
                            return;
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

void Validator :: validateSyntax(string label , string operation , string operand){
    findStart = false;
    checkSyntax( label ,  operation ,  operand);
    if(label != ""){

       if(notOk){
        string add = intToHexa(prevAddress);
        if(!findStart){
        labelInfo labelinfo(add , isAbsolute);
        sympolTable.insert(label , labelinfo);

        }

       }
        else if(isEQU){
        cout<<"shit"<<endl;
        labelInfo labelinfo(operand , isAbsolute);
        sympolTable.insert(label , labelinfo);

       //     sympolTable.insert(label , operand);

       }

       else if(!notOk){
                    cout<<"shit77"<<endl;

            string add = intToHexa(startAddress);
            if(!findStart){

            labelInfo labelinfo(add , isAbsolute);
            sympolTable.insert(label , labelinfo);


          //  sympolTable.insert(label , add);



            }
       }


    }

    cout<<notOk<<"!!!!!"<<endl;
}


bool Validator :: isValid(){

    return notOk;
}

HashTable<string , labelInfo> Validator :: getSympolTable(){

return sympolTable;

}



string Validator :: getError(){

    return error ;

}
