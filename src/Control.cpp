
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>

#include "Validator.h"
#include "Reading.cpp"
#include <iomanip>

#include <fstream>
#include <string>
using namespace std;

class Control{
private :
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
public :
void control(char* fileName)
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
    ifstream myfile (fileName);
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

                validator->validateSyntax(label,operation,operand);

                label= completeString(label,9);
                operation=completeString(operation,8);

                address=completeAddress(validator->getAddress());
                outputFile <<address+" "<<label<<operation<<operand<<endl;
                if(validator->isValid())
                {
                    outputFile<<validator->getError()<<endl;
                }

            }


        }
        outputFile<<"\n>>    e n d    o f   p a s s   1\n"<<endl;
        outputFile<<">>   *****************************************************"<<endl;
        HashTable <string,string>symTab=validator->getSympolTable();
        symTab.iterator();

        outputFile<<">>    s y m b o l     t a b l e   (values in decimal)\n"<<endl;
        outputFile<<"        name         value"<<endl;
        outputFile<<"        ------------------"<<endl;

        while(symTab.hasNext())
        {

            Entry<string,string>* element = symTab.next();
            string tmp = element->getValue();
            char buff[1024];
            strcpy(buff, tmp.c_str());
            long value = strtol(buff, NULL, 16);


            outputFile<<"        "<<completeString(element->getKey(),13)<<value<<endl;

        }









        outputFile<<"\n>>   *****************************************************"<<endl;


        myfile.close();
        outputFile.close();


        opTable->kill();
        read.kill();
    }

    else cout << "Unable to open file";



}


};
