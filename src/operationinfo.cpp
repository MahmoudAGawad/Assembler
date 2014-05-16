#include "operationinfo.h"
#include <iostream>
#include <strings.h>
using namespace std;

operationInfo::operationInfo()
{
    //ctor
}


operationInfo:: operationInfo(string name , bool need , int howMany , bool dir)
{
    //ctor
    operationName = name;
    registeronly = need;
    howManyOperand = howMany;
    directive = dir;
}


operationInfo::~operationInfo()
{
    //dtor
}
