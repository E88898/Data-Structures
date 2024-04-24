#include "DoublyList.h"

DoublyList::DoublyList()
	: _head{ nullptr },
	_tail(nullptr),
	_size{ 0 }
{
}

DoublyList::~DoublyList()
{
	while (_head != _tail) {
		_head = _head->next;
		delete _head->previous;
	}
	delete _tail;
}

void DoublyList::push_front(int number)
{
	node* newNode = new node;
	newNode->data = number;
	if (_head == _tail) {
		if (_head == nullptr) {
			_head = _tail = newNode;
		}
		else {
			_head = newNode;
			_head->next = _tail;
			_tail->previous = _head;
		}
	}
	else {
		_head->previous = newNode;
		newNode->next = _head;
		_head = newNode;
	}
	++_size;
}

void DoublyList::push_back(int number)
{
	node* newNode = new node;
	newNode->data = number;
	if (_head == _tail) {
		if (_head == nullptr) {
			_head = _tail = newNode;
		}
		else {
			_tail = newNode;
			_head->next = _tail;
			_tail->previous = _head;
		}
	}
	else {
		_tail->next = newNode;
		newNode->previous = _tail;
		_tail = newNode;
	}
	++_size;
}

void DoublyList::pop_front()
{
	if (_head == nullptr) {
		throw ListException{ "empty list" };
	}
	if (_head == _tail) {
		delete _head;
		_head = nullptr;
		_tail = nullptr;
	}
	else {
		_head = _head->next;
		delete _head->previous;
	}
	--_size;
}

void DoublyList::pop_back()
{
	if (_tail == nullptr) {
		throw ListException{ "empty list" };
	}
	if (_tail == _head) {
		delete _tail;
		_head = nullptr;
		_tail = nullptr;
	}
	else {
		_tail = _tail->previous;
		delete _tail->next;;
	}
	--_size;
}

void DoublyList::insert_after(node* n, int number)
{
	node* newNode = new node;
	newNode->data = number;
	if (n == _head && _head == _tail) {
		_head->next = newNode;
		newNode->previous = _head;
		newNode->next = _tail;
		_tail->previous = newNode;
	}
	else if (n == _head) {
		_head->next->previous = newNode;
		newNode->next = _head->next;
		newNode->previous = _head;
		_head->next = newNode;
	}
	else if (n == _tail) {
		_tail->next = newNode;
		newNode->previous = _tail;
		_tail = newNode;
	}
	else {
		n->next->previous = newNode;
		newNode->next = n->next;
		newNode->previous = n;
		n->next = newNode;
	}
	++_size;
}

void DoublyList::remove_after(node* n)
{
	if (n == _head && _head == _tail) {
		throw ListException{ "1 element in list. " };
	}
	else if (n == _head) {
		node* ptr = _head->next->next;
		delete _head->next;
		_head->next = ptr;
		ptr->previous = _head;
	}
	else if (n == _tail) {
		throw ListException{ "last element in list. " };
	}
	else {
		node* ptr = n->next->next;
		delete n->next;
		n->next = ptr;
		ptr->previous = n;
	}
	--_size;
}

int DoublyList::size() const
{
	return _size;
}


std::ostream& operator<<(std::ostream& out, const ListException& obj)
{
	out << obj.s;
	return out;
}
