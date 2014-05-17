#include "operationInfo.h"

//using namespace std;

operationInfo::operationInfo()
{
	this->operands = -1;
    this->format = "";
	this->opCode = "";
	this->regist = false;
}


operationInfo:: operationInfo(int operands, string format,
		string opCode, string register_)
{
    this->operands = operands;
    this->format = format;
    this->opCode = opCode;
    this->regist = (register_=="FALSE") ? false : true;
}


operationInfo::~operationInfo()
{
    //dtor
}
