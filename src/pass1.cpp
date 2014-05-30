/*
 * pass1.cpp
 *
 *  Created on: May 17, 2014
 *      Author: MahmoudSaleh
 */




#include <stdio.h>
#include <iostream>
#include "Control.cpp"
#include "Parser.h"
#include "Validator.h"
#include "operationInfo.h"
#include "GeneralTasks.h"
using namespace std;

int main(int argc, char* argv[]){

	cout << General::intToString(16);
	return 0;
	if (argc != 2) {
		fprintf(stderr, "Error: Invalid arguments.\n");
	    return -1; /* inform the parent process of the error */
	}
	printf("The assembly file is: %s\n", argv[1]);
	Control controler;
	controler.control(argv[1]);
	return 0;

}
