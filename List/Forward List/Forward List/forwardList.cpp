#include "ForwardList.h"

ForwardList::ForwardList()
	: _header{ nullptr }
{
}

ForwardList::~ForwardList()
{
	while (_header != nullptr) {
		node* ptr = _header;
		_header = _header->_next;
		delete ptr;
	}
}
void ForwardList::push_front(int number)
{
	node* ptr = new node;
	ptr->_data = number;
	if (!header) {
		header = ptr;
	}
	else {
		ptr->_next = header;
	}
}

void ForwardList::pop_front()
{
	if (_header == nullptr) {
		throw ListException{ "empty list" };
	}
	else {
		node* ptr = _header->_next;
		delete _header;
		_header = ptr;
	}
}

void ForwardList::push_back(int number) {
	
	if (!_header) {
		return;
	}

	node* ptr = _header;
	while (ptr->_next) {
		ptr = ptr->_next;
	}
	ptr->next = new node(number);
}

void ForwardList::insert_after(node* const n, int number)
{
	node* ptr = new node;
	ptr->_next = n->_next;
	ptr->_data = number;
	n->_next = ptr;
}

void ForwardList::remove_after(node* const n)
{
	if (n->_next = nullptr) {
		throw ListException{"last node"};
	}
	else {
		node* ptr = n->_next;
		n->_next = ptr->_next;
		delete ptr;
	}

}

void ForwardList::print(const int index) const
{
	node* ptr = _header;
	for (int i = 0; i <= index; ++i) {
		if (ptr == nullptr) {
			throw ListException{ "index out of bounds" };
		}
		if (i == index) {
			break;
		}
		ptr = ptr -> _next;
	}
	
	std::cout << ptr->_data;
}

int ForwardList::size() const
{
	int size = 0;
	node* ptr = _header;
	while (ptr != nullptr) {
		ptr = ptr->_next;
		++size;
	}
	return size;
}

node* ForwardList::getNode(const int index) const 
{
	node* ptr = _header;
	for (int i = 0; i < index; ++i) {
		ptr = ptr->_next;
	}
	return ptr;
}


std::ostream& operator<<(std::ostream& out, const ListException& obj)
{
	out << obj.s;
	return out;
}
