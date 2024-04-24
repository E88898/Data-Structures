#ifndef BTS_H
#define BTS_H
#include <iostream>
struct node {
	node(int x) : left{ nullptr }, right{ nullptr }, value{ x } {}
	node* left;
	node* right;
	int value;
};

class BTS {
public:
	BTS();
	void insert(int value);
	void remove(int value);
	void levelorderT(node* root);
	bool find(int value) const;
	node* getRoot() const;
	int getSize() const;
private:
	node* root;
	int _size;
};

struct BTSException {
	std::string s;
	void what() {
		std::cout << s;
	}
};

#endif
