#include "operationInfo.h"


operationInfo::operationInfo()
{
    //ctor
    //temp;
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
