
#include <iostream>
#include <sstream>

#include "Parser.cpp"
#include "Validator.h"

#include <fstream>
#include <string>
using namespace std;

int main()
{
    Parser parser;//Paser OBJECT

//    Validator validator;

    string line;
    ifstream myfile ("src.txt");
    ofstream outputFile;
    outputFile.open("LISAFILE.txt");
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {

            parser.setParsingLine(line);
            parser.parse();
            cout<<parser.isComment();
            cout<<line<<endl;
            if(parser.isComment()||parser.isInValid())
            {
                outputFile << line << endl;
            }
            else
            {
                cout<<line<<endl;

            }


        }
        myfile.close();
        outputFile.close();




    }

    else cout << "Unable to open file";



    return 0;
}
