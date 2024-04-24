#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <vector>

struct node {
	node* _next;
	int _value;
};

class HashTable {
public:
	HashTable();
	~HashTable();
	void insert(const int y);
	void remove(const int y);
	bool find(const int y) const;

	void print(int idx) const;
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
	unsigned hash(const int x) const;
	void reHashing();
};

#endif
