#include "labelInfo.h"

labelInfo::labelInfo(string add , bool abs)
{
    //ctor
    address = add;
    absolute = abs;

}

labelInfo::labelInfo()
{
    //ctor
    address = "";
    absolute = false;

}


labelInfo::~labelInfo()
{
    //dtor
}

string labelInfo:: getAddress(){

    return address;

}

bool labelInfo :: isAbsolute(){

    return absolute;
}
