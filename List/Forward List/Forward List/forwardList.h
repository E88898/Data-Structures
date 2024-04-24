#ifndef FORWARDLIST_H
#define FORWARDLIST_H
#include <iostream>

struct node {
	node() : _next{ nullptr }, _data{ 0 } {};
	node* _next;
	int _data;
};

class ForwardList {
public:
	ForwardList();
	~ForwardList();
	void push_front(const int number);
	void pop_front();
	void push_back(const int number);

	void insert_after(node* const n, const int number);
	void remove_after(node* const n);

	void print(const int index) const;
	int size() const;
	node* getNode(const int index) const;

private:
	node* _header;
};

struct ListException {
	std::string s;
	friend std::ostream& operator<<(std::ostream& out, const ListException& obj);

};

#endif
