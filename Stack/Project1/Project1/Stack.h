#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <vector>

class Stack {
public:
	Stack();
	Stack(int num);
	void push(int num);
	void pop();
	int top();
	int size();
	bool empty();
	int operator[](int idx);
	
private:
	std::vector<int> _data;
	
};

struct StackException {
	std::string s;
	friend std::ostream& operator<<(std::ostream& out, const StackException& obj);
};

#endif
