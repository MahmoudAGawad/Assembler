/*
 * GeneralTasks.cpp
 *
 *  Created on: May 30, 2014
 *      Author: Mahmoud Saleh <3 Waleed Adel
 */
#include "GeneralTasks.h"

int General::binaryToDecimal(string binary){

    char buff[1024];
    strcpy(buff, binary.c_str());
	return (int)strtol(buff, NULL, 2);
}

int General::hexaToDecimal(string hexa){

    char buff[1024];
    strcpy(buff, hexa.c_str());
	return (int)strtol(buff, NULL, 16);
}


string General::decimalToBinary(int n){
	char bin[100];
	itoa(n,bin,2);
	return string(bin);
}

string General::decimalToHexa(int n){
	char bin[100];
	itoa(n,bin,16);
	return string(bin);
}



string General::binaryToHexa(string bin){
	int dec = binaryToDecimal(bin);
	return decimalToHexa(dec);
}

string General::hexaToBinary(string hexa){

	int dec = hexaToDecimal(hexa);
	return decimalToBinary(dec);
}


string General::intToString(int n){
	char arr[20];
	itoa(n,arr,10);
	return string(arr);
}

int General::stringToInt(string s){
	return atoi(s.c_str());
}

string General::toUpper(string n){
	for(int i=0;i<n.length();i++){
		n[i]=toupper(n[i]);
	}
	return n;
}
string General::toLower(string n){
	for(int i=0;i<n.length();i++){
		n[i]=tolower(n[i]);
	}
	return n;
}
