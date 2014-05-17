/*
 * Reading.cpp
 *
 *  Created on: May 17, 2014
 *      Author: MahmoudSaleh
 */
#include <strings.h>
#include <fstream>
#include <iostream>
#include "includes.h"
using namespace std;

class Reading{
public:

	~Reading(){
		delete opTable;
	}

	HashTable<string,operationInfo>* read(){ // file name + extension
		ifstream file("Operations Table.txt");
		opTable = new HashTable<string,operationInfo>;

		// Directive
		opTable->insert("START", operationInfo());
		opTable->insert("END", operationInfo());
		opTable->insert("WORD", operationInfo());
		opTable->insert("RESW", operationInfo());
		opTable->insert("RESB", operationInfo());
		opTable->insert("BYTE", operationInfo());
		// end directive

		string _operator, format, opCode, registerBoolean;
		int numberOfOperand;
		while(file >> _operator >> numberOfOperand >> format >> opCode >> registerBoolean){
			cout << _operator << " " << numberOfOperand << " " <<format<<" "<<opCode <<" " << registerBoolean<<endl;
			opTable->insert(_operator, operationInfo(numberOfOperand, format, opCode, registerBoolean));
		}
		cout << "FiNISH\n";
		return opTable;
	}

private:
	HashTable<string,operationInfo> *opTable;
};


