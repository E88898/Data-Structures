#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <vector>
#include <iostream>

struct pair {
	int _key;
	std::string _value;
};

struct node {
	node* _next;
	pair _value;
};

class HashTable {
public:
	HashTable();
	~HashTable();
	void insert(const int key, const std::string& value);
	void remove(const int key);
	pair find(const int key) const;
	std::string& operator[](const int key) const;
	void print(const int idx) const;
	int size() const;

	struct HashTableException {
		void what() {
			std::cout << s;
		}
		std::string s;
	};

private:
	std::vector<node*> _data;
	int _size;
	static double loadFactor;
	unsigned hash(const int key) const;
	void reHashing();
};




#endif
