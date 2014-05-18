#include "operationInfo.h"

using namespace std;

operationInfo::operationInfo()
{
	this->operands = -1;
    this->format = "";
	this->opCode = "";
	this->regist = _register = false;
	this->directive = true;
}

operationInfo::operationInfo(bool reg)
{
	this->operands = -1;
    this->format = "";
	this->opCode = "";
	this->regist = false;
	_register = reg;
	this->directive = true;
}


operationInfo:: operationInfo(int operands, string format,
		string opCode, string register_)
{
    this->operands = operands;
    this->format = format;
    this->opCode = opCode;
    this->regist = (register_=="FALSE") ? false : true;
    this->directive = _register = false;
}



int operationInfo::getOperands(){
	return operands;
}

bool operationInfo::isDirective(){
	return directive;
}

bool operationInfo::isRegisiterOnly(){
	return regist;
}

bool operationInfo::isRegister(){
	return _register;
}

string operationInfo::getFormat(){
	return format;
}

string operationInfo::getOpCode(){
	return opCode;
}
