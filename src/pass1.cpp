/*
 * pass1.cpp
 *
 *  Created on: May 17, 2014
 *      Author: MahmoudSaleh
 */




#include <stdio.h>
#include "includes.h"
#include "Control.cpp"
int main(int argc, char* argv[]){


	Control controler;
	char* name = "C:/Users/MahmoudSaleh/Desktop/Assembler_Tests/TEST_04";
	controler.control("src.txt");
	return 0;

}
