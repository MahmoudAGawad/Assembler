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
		delete [] table;
		table = 0;
	}

	bool insert(K key, V value);
	bool _delete(K key);
	V get(K key);
	int size(){return entries;}

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

template<class K, class V>
bool HashTable<K,V>::Do(int operation, K key, V& value)
{
	int index = hash(key)%_SIZE, stepi = 0, prev=index;
	Entry<K,V> *entry = &table[index];
	//cout << "Insert: "<<key<<" "<<value << "\n";
	while(entry!=NULL && entry->isInit()){
		//cout << "At = " << prev << endl;
		switch(operation){
		case SEARCH:
			if(!entry->isTombstone() &&key == entry->getKey()){
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
			if(!entry->isTombstone() &&key == entry->getKey()){
				entry->setValue(value);
				return true;
			}
			break;

		case DELETE:
			if(!entry->isTombstone() &&key == entry->getKey()){
				delete(entry);
				entry = 0;
				entries--;
				return true;
			}
			break;
		}

		entry = &table[prev=((index+step(++stepi))%_SIZE)];
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




