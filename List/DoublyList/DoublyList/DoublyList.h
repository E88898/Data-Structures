#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H
#include <iostream>
struct node {
	node* previous;
	node* next;
	int data;
};

class DoublyList {
public:
	DoublyList();
	~DoublyList();

	void push_front(int number);
	void push_back(int number);

	void pop_front();
	void pop_back();

	void insert_after(node* n, int number);
	void remove_after(node* n);

	int size() const;

private:
	node* _head;
	node* _tail;
	int _size;
};

struct ListException {
	std::string s;
	friend std::ostream& operator<<(std::ostream& out, const ListException& obj);
};
#endif
