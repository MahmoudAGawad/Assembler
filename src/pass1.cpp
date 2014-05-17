/*
 * pass1.cpp
 *
 *  Created on: May 17, 2014
 *      Author: MahmoudSaleh
 */




#include <stdio.h>
#include "includes.h"
int main(int argc, char* argv[]){

	if(argc!=2){
		fprintf(stderr, "Error: Invalid arguments.\n");
		return -1;
	}

	printf("The assembly file is: %s\n", argv[1]);

	return 0;

}
