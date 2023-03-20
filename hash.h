#pragma once
#ifndef HASH_H
#define HASH_H
template<typename K, typename V>
class hash_node {
private:
	K key;
	V value;
public:
	hash_node(K, V);
};
template<typename K, typename V>
hash_node<K, V>::hash_node(K key, V value):key(key), value(value) {

}
template<typename K, typename V>
class hash_table {
private:
	hash_node<K, V>** arr;
	int capacity=1024;
	int current_nodes=0;
public:
	hash_table();
	int hash_code(K key);
	void insert_node(K, V);
};
#endif

template<typename K, typename V>
hash_table<K, V>::hash_table()
{
	this->arr = new hash_node<K, V>*[this->capacity];

}

template<typename K, typename V>
inline int hash_table<K, V>::hash_code(K key)
{
	return key%capacity;
}

template<typename K, typename V>
void hash_table<K, V>::insert_node(K, V)
{
	// Apply hash function to find index for given key
	int hashIndex = hashCode(key);

	// find next free space
	while (arr[hashIndex] != NULL
		&& arr[hashIndex]->key != key
		&& arr[hashIndex]->key != -1) {
		hashIndex++;
		hashIndex %= capacity;
	}
	if (arr[hashIndex] == nullptr || arr[hashIndex]->key == -1) {
		size++;
	}
		
	arr[hashIndex] = new HashNode<K, V>(key, value);
}
