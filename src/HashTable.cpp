/*
 * HashTable.cpp
 *
 *  Created on: May 14, 2014
 *      Author: MahmoudSaleh
 */

#include <iostream>
#include <stdlib.h>
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

template <class K, class V>
class HashTable {
public:
	HashTable(){
		entries = 0;
		_SIZE=16;
		table = new Entry<K,V>[_SIZE];
	}

	~HashTable(){
		cout << "Destructor!!\n";
		delete [] table;
		table = 0;
		cout << "Destructor!!\n";
	}

	bool insert(K key, V value);
	bool _delete(K key);
	V get(K key);
	int size(){return entries;}
	void printAll();


private:
	Entry<K,V> *table;
	int hash(K key);
	int step(int k);// quadratic probing >> step (i*(i+1)/2)
	bool Do(int operation, K key, V& value);
	void resize();


protected:
	int _SIZE, entries;
	static const int SEARCH = 0, INSERT = 1, UPDATE = 2, DELETE = 3;
};



template<class K, class V>
int HashTable<K,V>::hash(K key)
{

	return 0;
}

template<class K, class V>
int HashTable<K,V>::step(int i)
{
	return (i*(i+1))>>1;
}

template <typename T>
inline int comp (T const& a, T const& b)
{
    return a == b ? 0: a>b?1:-1;
}


template<class K, class V>
bool HashTable<K,V>::Do(int operation, K key, V& value)
{
	int index = hash(key)%_SIZE, stepi = 0, prev=index, orignal = index;
	Entry<K,V> *entry = &table[index];
	cout << "Operation: "<<operation << " "<<key<<" "<<value << "\n";
	while(entry!=NULL && entry->isInit()){
		cout << "At = " << prev << endl;
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
	return Do(INSERT,key,value);
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
void HashTable<K,V>::resize()
{

}

template <class K, class V>
void HashTable<K,V>::printAll()
{

		int e=1;
		cout << "===============================HashTable===============================\n";
		for(int i=0;i<_SIZE;i++){
			if(table[i].isInit()&& !table[i].isTombstone()){
				cout << "Entry #"<<e++<<": "<<"[Key="<<table[i].getKey()<<", Value="<<table[i].getValue()<<"]\n";
			}
		}
		cout << "=======================================================================\n";

}




