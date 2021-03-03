#pragma once
#include <vector>
#include <iostream>
#include <list>
using namespace std;


template<class T, class U>
struct Hash_Node
{
	T key;
	U value;
};
const int hashsize = 12;
template<class T, class U>
class HashTable
{
private:
	vector<list<Hash_Node<T, U> > > vector_node;

public:
	HashTable() :vector_node(hashsize) {}
	~HashTable() {}
	bool insert(const T& key, const U& value);//bool ºÍ const &
	bool find(const T& key);
	int hash(const T& key);

};


template<class T, class U>
bool HashTable<T, U>::insert(const T& key, const U& value)
{
	Hash_Node<T, U> node;
	node.key = key;
	node.value = value;
	for (unsigned int i = 0; i < vector_node.size(); i++)
	{
		if (i == hash(key))
		{
			vector_node[i].push_back(node);
			return true;
		}
	}
	return false;
}
template<class T, class U>
int HashTable<T, U>::hash(const T& key)
{
	return key % 13;
}
template<class T, class U>
bool HashTable<T, U>::find(const T& key)
{
	int index = hash(key);
	for (list<Hash_Node<T, U> >::iterator it = vector_node[index].begin(); it != vector_node[index].end(); it++)
	{
		if (it->key == key)
		{
			cout <<endl<<"find is " <<it->value<<endl;
			return true;
		}
	}
	return false;
}
//int main()
//{
//	HashTable<int, int> h;
//
//	for (int i = 0; i < 10; i++)
//	{
//		h.insert(i, i + 1);
//	}
//	h.find(1);
//
//
//	return 0;
//}