
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include "Parser.h"
#include "Validator.h"
#include "Reading.cpp"
#include <iomanip>

#include <fstream>
#include <string>
using namespace std;
string completeString(string str,int len)
{
    int l=str.length();
    for(int i=l; i<len; i++)
    {
        str+=" ";
    }
    return str;
}
string completeAddress(string str)
{
    int l=str.length();
    for(int i=l; i<6; i++)
    {
        str="0"+str;
    }
    return str;
}
int main()
{
    Parser parser;//Paser OBJECT
    Reading read;
    HashTable<string,operationInfo>*opTable =  read.read();

    Validator *validator=new Validator(*opTable);
    string label;
    string operation;
    string operand;
    string address;
    string line;
    ifstream myfile ("src.txt");
    ofstream outputFile;
    outputFile.open("LISAFILE.txt");
    outputFile<<">>  Source Program statements with value of LC indicated\n"<<endl;
    if (myfile.is_open())
    {
        while (! myfile.eof() )
        {
            line="";
            getline (myfile,line);

            parser.setParsingLine(line);
            parser.parse();

            if(parser.isComment()||parser.isInValid())
            {
                outputFile << "      "<<line << endl;

            }
            else

            {
                label=parser.getLabel();
                operation=parser.getOperation();
                operand=parser.getOperand();
//                cout<<label<<"\t"<<operation<<"\t"<<operand<<endl;
                validator->validateSyntax(label,operation,operand);


                label= completeString(label,9);
                operation=completeString(operation,8);

                cout<<validator->getAddress()<<endl;
                address=completeAddress(validator->getAddress());
                outputFile <<address<<label<<operation<<operand<<endl;
                if(!validator->isValid())
                {
                    outputFile<<"\t\t"<<validator->getError()<<endl;
                }

            }


        }
        outputFile<<"\n>>    e n d    o f   p a s s   1\n"<<endl;
        outputFile<<">>   *****************************************************"<<endl;
        outputFile<<">>    s y m b o l     t a b l e   (values in decimal)\n"<<endl;
        outputFile<<"        name         value"<<endl;
        outputFile<<"        ------------------"<<endl;




        outputFile<<"\n>>   *****************************************************"<<endl;


        myfile.close();
        outputFile.close();




    }

    else cout << "Unable to open file";



    return 0;
}


