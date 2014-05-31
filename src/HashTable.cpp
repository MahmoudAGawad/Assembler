/*
 * HashTable.cpp
 *
 *  Created on: May 14, 2014
 *      Author: MahmoudSaleh
 */

#include <iostream>
#include <stdlib.h>
#include <string>
#include <functional>
using namespace std;


template <class K, class V>
class Entry{
public:

	Entry(){
		tombstone = init = false;
	}

	Entry(K key, V value){
		this->key = key;
		this->value = value;
		tombstone = false;
		init = true;
	}

	void setKey(V newKey){this->key = newKey;}
	void setValue(V newValue){this->value = newValue;}
	void setTombstone(bool tomb){this->tombstone = tomb;}
	void setInit(bool in){init = in;}

	V getValue(){return value;}
	K getKey(){return key;}
	bool isTombstone(){return tombstone;}
	bool isInit(){return init;}

	void initialize(K k, V v){
		key = k;
		value = v;
		tombstone = false;
		init = true;
	}

private:
	K key;
	V value;
	bool tombstone, init;


};

template <class T>
class Hash {
public:
	static unsigned int hash(T key){
		return (unsigned int)key;
	}
};

template <>
class Hash <string> {
public:
	static unsigned int hash(string key){
		unsigned int hash = 5381;
		int i=0,len = key.length();
		while (i<len){
		    hash = ((hash << 5) + hash) + key[i++];
		}
		return hash;
	}
};

template <class K, class V>
class HashTable {
public:
	HashTable(){
		entries = cursor = 0;
		_SIZE=128;
		table = new Entry<K,V>[_SIZE];
	}

    void init(){
        kill();

        entries = cursor = 0;
		_SIZE=128;
		table = new Entry<K,V>[_SIZE];
    }
	bool insert(K key, V value);
	bool _delete(K key);
	V get(K key);
	int size(){return entries;}
	void printAll();
	bool containsKey(K key);
	bool containsValue(V value);
	void iterator(){
		cursor = getNext(0);
	}

	Entry<K,V>* next(){
		Entry<K,V>* e=0;
		int index=cursor;
		if(cursor==_SIZE){return e;}
		cursor=getNext(cursor+1);
		return &table[index];
	}

	bool hasNext(){
		return cursor<_SIZE;
	}

	void kill(){
		delete [] table;
		table = 0;
		cout << "Destructor!!\n";
	}
private:
	Entry<K,V> *table;
	int cursor;
	int step(int k){	// quadratic probing >> step (i*(i+1)/2)
		return (k*(k+1))>>1;
	}
	bool Do(int operation, K key, V& value);
	void resize();
	int getNext(int cursor){
		for(;cursor<_SIZE;cursor++){
			if(!table[cursor].isTombstone() && table[cursor].isInit()){
				break;
			}
		}
		return cursor;
	}

protected:
	int _SIZE, entries;
	static const int SEARCH = 0, INSERT = 1, UPDATE = 2, DELETE = 3;
};



template <typename T>
inline int comp (T const& a, T const& b)
{
    return a == b ? 0: a>b ? 1 : -1;
}


template<class K, class V>
bool HashTable<K,V>::Do(int operation, K key, V& value)
{
	int index = Hash<K>::hash(key)%_SIZE;
	int stepi = 0, prev=index, orignal = index;
	Entry<K,V> *entry = &table[index];
	//cout << "Operation: "<<operation << " "<<key<<" "<<value << "\n";
	while(entry!=NULL && entry->isInit()){
		//cout << "At = " << prev << endl;
		switch(operation){
		case SEARCH:
			if(!entry->isTombstone() && comp(key,entry->getKey())==0){
				value = entry->getValue();
				return true;
			}
			break;

		case INSERT:
			if(entry->isTombstone()){
				entry->initialize(key,value);
				entries++;
				return true;
			}
			break;

		case UPDATE:
			if(!entry->isTombstone() && comp(key,entry->getKey())==0){
				entry->setValue(value);
				return true;
			}
			break;

		case DELETE:
			if(!entry->isTombstone() && comp(key,entry->getKey())==0){

				entry->setTombstone(true);
				entries--;
				return true;
			}
			break;
		}

		entry = &table[prev=((index+step(++stepi))%_SIZE)];
		if(prev==orignal)
			break;
	}

	if(operation == INSERT){
		entry = &table[prev];
		entry->initialize(key, value);
		//cout << "Inserted at Index: "<<prev<<endl;
		entries++;
		return true;
	}

	return false;
}

template<class K, class V>
bool HashTable<K,V>::insert(K key, V value)
{
	bool ret = Do(UPDATE,key,value)?true:Do(INSERT,key,value);
	if(entries*100/_SIZE>75) // if load factor is greater than 75%
		resize();
	return ret;
}

template<class K, class V>
bool HashTable<K,V>::_delete(K key)
{
	V v;
	return Do(DELETE,key,v);
}


template <class K, class V>
V HashTable<K,V>::get(K key)
{
  V retval;
  Do(SEARCH,key,retval);
  return retval;
}

template <class K, class V>
bool HashTable<K,V>::containsKey(K key)
{
  V retval;
  return Do(SEARCH,key,retval)?true:false;
}

template <class K, class V>
bool HashTable<K,V>::containsValue(V value)
{
	iterator();
	while(hasNext()){
		if(comp(next()->getValue(),value)==0){
			return true;
		}
	}
	cursor = 0;
	return false;
}



template <class K, class V>
void HashTable<K,V>::resize()
{
	int prevSize = _SIZE;
	Entry<K,V>* prevTable = table;
	table = new Entry<K,V>[_SIZE<<=1];
	Entry<K,V>* temp;
	entries = 0;
	for(int i=0;i<prevSize;i++){
		temp = &prevTable[i];
		if(temp!=NULL && temp->isInit() && !temp->isTombstone()){
			V v = temp->getValue();
			if(!Do(INSERT, temp->getKey(), v )){
				cout << "An Error occured while resizing!\n";
			}
			temp->setValue(v);
		}
	}

	delete[] prevTable;
}

template <class K, class V>
void HashTable<K,V>::printAll()
{

		cout << "===============================HashTable["<<entries<<" keys]===============================\n[";
		for(int i=0;i<_SIZE;i++){
			if(table[i].isInit()&& !table[i].isTombstone()){
				cout <<" [Key="<<table[i].getKey()<<", Value="<<table[i].getValue()<<"],";
			}
		}
		cout << "]\n==================================================================================\n";

}




