#ifndef LABELINFO_H
#define LABELINFO_H

#include <iostream>
#include <string.h>

using namespace std;
class labelInfo
{
    public:
        labelInfo();
        labelInfo(string add , bool abs);
        ~labelInfo();
        string getAddress();
        bool isAbsolute();

    private:
        string address ;
        bool absolute;
};

#endif // LABELINFO_H
