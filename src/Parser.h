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
bool isComment();
  void parse();
  string getLabel();
  string getOperation();
  string getOperand();
  bool isInValid();
       virtual ~Parser();
    protected:
    private:
    string splittedLine;  //arr
     string label;
     string operation;
     string operand;
     bool isCommentVar;
     bool isInValidVar;
 vector<string> split(string str);
   bool checkComment(vector<string> splittedWords);
void connectWords(vector<string> splittedWords);
void connectOperand(vector<string> splittedWords);
bool isRsub(vector<string> splittedWords);
bool isEnd(vector<string> splittedWords);
bool isStart(vector<string> splittedWords);
bool checkForComma(vector<string> splittedWords);
int commaTypeMethod(vector<string> splittedWords);


};

#endif // PARSER_H
