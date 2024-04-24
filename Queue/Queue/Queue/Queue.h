#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>

class Queue {
public:
	Queue();
	Queue(const int num, const int capacity);
	Queue(const Queue& obj);
	Queue& operator=(const Queue& obj);
	~Queue();

	void push(const int num);
	void pop();

	int front() const;
	int back() const;

	int size() const;
	int operator[](const int idx) const;

private:
	int* _data;
	int _front;
	int _back;
	int _capacity;
	int _itemCount;
	bool isEmpty() const;
	bool isFull() const;
	bool validCapacity(const int capacity) const;

};
struct QueueException {
	std::string s;
	friend std::ostream& operator<<(std::ostream& out, QueueException& obj);
};
#endif
