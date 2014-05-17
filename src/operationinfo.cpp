#include "operationInfo.h"

//using namespace std;

operationInfo::operationInfo()
{
    //ctor
    //temp;
    operationName = "s";
    cout<<"fuck"<<endl;
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
