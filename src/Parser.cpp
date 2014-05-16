/*
 * Validator.cpp
 *
 *  Created on: May 16, 2014
 *      Author: waleed Adel
 */

#include "Parser.h"

Parser::Parser()
{
 splittedLine="";
 label="";
 operation="";
 operand="";
 isCommentVar=false;
 isInValidVar=false;
}


void Parser::parse(){
   vector<string> splittedWords;
 //  string c= "stl str,x";
   splittedWords=split(splittedLine);
    connectWords(splittedWords);
}


void Parser::setParsingLine(string str){
splittedLine=str;
}

vector<string>Parser::split(string str){

    string buf;
    stringstream ss(str);

    vector<string> tokens;

    while (ss >> buf)
        tokens.push_back(buf);

// for (vector<string>::iterator it = tokens.begin(); it != tokens.end(); ++it)
//    cout <<*it<<'#';
//  cout << '\n';

 return tokens;
}

void Parser::connectWords(vector<string> splittedWords){

 // not comment nor rsub

 if(isComment(splittedWords)){

   isCommentVar=true;
  }

 else if(isRsub(splittedWords)){
    operation=splittedWords.at(0);
 }

else{
        if(splittedWords.size()>5){isInValidVar=true;}
        else if(splittedWords.size()>=2){

  connectOperand(splittedWords);

             }
    else{
        isInValidVar=true;
    }
}
  // then add first label to first column of array if found
  // and operation to the second comlumn
  // and operand to the third column

}


void Parser::connectOperand(vector<string> splittedWords){

   if(checkForComma(splittedWords)){

      int commaType=commaTypeMethod(splittedWords);
  //     cout<<commaType<<endl;
     switch(commaType){

 case 1:
        operand=splittedWords.at(splittedWords.size()-1);
      operation=splittedWords.at(splittedWords.size()-2);
      if(splittedWords.size()==3){
        label=splittedWords.at(splittedWords.size()-3);
      }
      else{isInValidVar=true;}
     break;
 case 2:
      operand="";
     operand+=splittedWords.at(splittedWords.size()-3);
     operand+=splittedWords.at(splittedWords.size()-2);
     operand+=splittedWords.at(splittedWords.size()-1);

     operation=splittedWords.at(splittedWords.size()-4);

     if(splittedWords.size()==5){
        label=splittedWords.at(splittedWords.size()-5);
     }
     else{
        isInValidVar=true;
     }
     break;
 case 3:
 case 4:
        operand="";
     operand+=splittedWords.at(splittedWords.size()-2);
     operand+=splittedWords.at(splittedWords.size()-1);
       operation=splittedWords.at(splittedWords.size()-3);
     if(splittedWords.size()==4){
        label=splittedWords.at(splittedWords.size()-4);
     }
     else{
        isInValidVar=true;
     }
     break;
  default:
      isInValidVar=true;
    break;
     }

      }
else{
      operand=splittedWords.at(splittedWords.size()-1);
      operation=splittedWords.at(splittedWords.size()-2);
      if(splittedWords.size()==3){
        label=splittedWords.at(splittedWords.size()-3);
      }
      else{
        isInValidVar=true;
      }
}

}


bool Parser::isComment(vector<string> splittedWords){

string str=splittedWords.at(0);

 if(str.at(0)=='.'){
        isCommentVar=true;
         return true;
  }
 else{
    return false;
 }

}

bool Parser::isRsub(vector<string> splittedWords){

    if(splittedWords.size()==1){
        if(splittedWords.at(0)=="RSUB"||splittedWords.at(0)=="rsub"){
            return true;
        }
    }

return false;
}


bool Parser::checkForComma(vector<string> splittedWords){
// search for commas' location
  if(splittedWords.size()>1){
  string lastWord=splittedWords.at(splittedWords.size()-1);
   if(lastWord.size()>1){
   if(lastWord.at(lastWord.size()-2)==','){
    return true;
   }
}

  string beforeLastWord= splittedWords.at(splittedWords.size()-2);
    if(beforeLastWord.size()>0){
    if(beforeLastWord.at(beforeLastWord.size()-1)==','){
    return true;
   }
  }
  }
return false;
}

int Parser::commaTypeMethod(vector<string> splittedWords){

if(splittedWords.size()>1){
  string lastWord=splittedWords.at(splittedWords.size()-1);
   if(lastWord.size()>1){
   if((lastWord.at(lastWord.size()-2)==',')&&(lastWord.at(0)==',')){
                   return 4;
   }
   else{
           return 1;
   }
}

  string beforeLastWord= splittedWords.at(splittedWords.size()-2);
    if(beforeLastWord.size()>0){
    if((beforeLastWord.at(beforeLastWord.size()-1)==',')&&(beforeLastWord.at(0)==',')){
            return 2;
   }
   else{
     return 3;
   }
}
     }

return 0;
     }

bool Parser::isInValid(){
return isInValidVar;
}

string Parser::getLabel(){
return label;
}

string Parser::getOperation(){
return operation;
}

string Parser::getOperand()
{
return operand;
}



Parser::~Parser()
{
    //dtor
}
