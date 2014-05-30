/*
 * GeneralTasks.h
 *
 *  Created on: May 30, 2014
 *      Author: MahmoudSaleh
 */

#ifndef GENERALTASKS_H_
#define GENERALTASKS_H_

#include <strings.h>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


class General{
public:
	static int binaryToDecimal(string binary);
	static int hexaToDecimal(string hexa);

	static string decimalToBinary(int decimal);
	static string hexaToBinary(string hexa);

	static string decimalToHexa(int decimal);
	static string binaryToHexa(string binary);

	static string intToString(int n);
	static int stringToInt(string n);
	static string toUpper(string n);
	static string toLower(string n);
};


#endif /* GENERALTASKS_H_ */
