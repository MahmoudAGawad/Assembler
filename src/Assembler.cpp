//============================================================================
// Name        : Assembler.cpp
// Author      : Mahmoud A.Gawad, Mostafa Hamdy, Waleed Adel, Diaa Ibrahim, and Abdallah El-Abasery
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <sstream>
#include "Validator.h"
#include "Reading.cpp"
using namespace std;

int main(){
	Reading read;
		read.read();
		return 0;
	HashTable<string,string> ht;
		string key="Key#",num,aa,bb,val="Value#";
		for(int i=0;i<16;i++){
			num = static_cast<ostringstream*>( &(ostringstream() << i) )->str();
			aa = key + num;
			bb = val + num;
			ht.insert(aa,bb);
		}
		cout << ht.size()<<endl;

		ht.printAll();
		for(int i=0;i<16;i++){
			num = static_cast<ostringstream*>( &(ostringstream() << i) )->str();
			aa = key + num;
			cout << ht._delete(aa)<<endl;
		}

		val = "second#";
		for(int i=20;i<30;i++){
			num = static_cast<ostringstream*>( &(ostringstream() << i) )->str();
			aa = key + num;
			bb = val + num;
			ht.insert(aa,bb);
		}

		ht.printAll();
		cout << ht.size()<<endl;

		cout << (ht.containsKey("Key#22")?"Found\n":"NOT Found\n");
		cout << (ht.containsValue("second#22")?"Found\n":"NOT Found\n");

		ht.iterator();
		Entry<string,string>* entry;
		while(ht.hasNext()){
			entry = ht.next();
			cout<<"Key = "<< entry->getKey()<<" | Value = "<< entry->getValue()<<endl;
		}

		HashTable<int,string> a;
		a.insert(100,"File");
		a.printAll();

	return 0;
}
