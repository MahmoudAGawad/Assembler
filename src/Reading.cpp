/*
 * Reading.cpp
 *
 *  Created on: May 17, 2014
 *      Author: MahmoudSaleh
 */
#include <strings.h>
#include <fstream>
#include <iostream>
#include "HashTable.cpp";
#include "operationinfo.h"

using namespace std;

class Reading{
public:

	~Reading(){
		delete opTable;
	}

	HashTable<string,operationInfo>* read(){ // file name + extension
		ifstream file("Operations Table.txt");
		opTable = new HashTable<string,operationInfo>;
		string firstLine;
		int i=6;
		while(i--){
			file>>firstLine;
			opTable->insert(firstLine, operationInfo());
		}
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


