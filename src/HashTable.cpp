/*
 * HashTable.cpp
 *
 *  Created on: May 14, 2014
 *      Author: MahmoudSaleh
 */

#include <iostream>
using namespace std;


template <class K, class V>
class HashTable {
public:
	HashTable(){
		_size = 0;
		table = new V[16];
	}
	~HashTable(){
		delete(table);
	}
	bool insert(K key, V value);
	bool _delete(K key);
	V get(K key);
	int size();
private:
	V table[];
	int hash(K key);
	int step(int k);// quadratic probing >> step (i*(i-1)/2)
	bool Do(int operation, K key, V value);
	void resize();
protected:
	int _size;
	const int SEARCH = 0, INSERT = 1, UPDATE = 2, DELETE = 3;
};

template<class K, class V>
int HashTable<K,V>::hash(K key)
{

	return 0;
}

template<class K, class V>
int HashTable<K,V>::step(int i)
{
	return i*(i+1)/2;
}

template<class K, class V>
bool HashTable<K,V>::Do(int operation, K key, V value)
{

	return false;
}

template<class K, class V>
bool HashTable<K,V>::insert(K key, V value)
{

	return false;
}

template<class K, class V>
bool HashTable<K,V>::_delete(K key)
{

	return false;
}


template <class K, class V>
V HashTable<K,V>::get(K key)
{
  V retval;
  return retval;
}

template <class K, class V>
void HashTable<K,V>::resize()
{

}

template <class K, class V>
int HashTable<K,V>::size()
{
  return _size;
}
