//============================================================================
// Name        : Assembler.cpp
// Author      : Mahmoud A.Gawad, Mostafa Hamdy, Waleed Adel, Diaa Ibrahim, and Abdallah El-Abasery
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "HashTable.cpp"
using namespace std;

int main(){

	HashTable<int,int> ht;
	for(int i=0;i<16;i++)
		ht.insert(i,i*100);
	cout << ht.size()<<endl;
	for(int i=0;i<16;i++)
	cout << ht.get(i) <<endl;

	for(int i=0;i<16;i++)
		cout << ht._delete(i)<<endl;

	cout << ht.size()<<endl;
	return 0;
}
