#ifndef PARSER_H
#define PARSER_H
#include <vector>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Parser
{
    public:
        Parser();
     void setParsingLine(string str);
bool isComment(vector<string> splittedWords);
       virtual ~Parser();
    protected:
    private:
    string splittedLine;  //arr
     string label;
     string operation;
     string operand;
     bool isCommentVar;
     bool isValidVar;
 vector<string> split(string str);
void connectWords(vector<string> splittedWords);
void connectOperand(vector<string> splittedWords);
bool isRsub(vector<string> splittedWords);
bool checkForComma(vector<string> splittedWords);
int commaTypeMethod(vector<string> splittedWords);


};

#endif // PARSER_H
