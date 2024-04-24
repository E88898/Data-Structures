#include "HashTable.h"

double HashTable::loadFactor = 0.7;

HashTable::HashTable()
	:_data(5,nullptr),
	_size{0}
{
}

HashTable::~HashTable()
{
	for (int i = 0; i < _data.size(); ++i) {
		node* front = _data[i];
		while (front) {
			node* back = front;
			front = front->_next;
			delete back;
		}
	}
}

void HashTable::insert(const int y)
{
	if (_data.size() * loadFactor <= _size) {
		reHashing();
	}
	int idx = hash(y) % _data.size();
	node* front = _data[idx];
	while (front) {
		if (front->_value == y) {
			throw HashTableException{ "there is a value in list" };
		}
		else {
			front = front->_next;
		}
	}
	node* ptr = new node;
	ptr->_value = y;
	ptr->_next = _data[idx];
	_data[idx] = ptr;
	++_size;
}

void HashTable::remove(const int y)
{
	int idx = hash(y) % _data.size();
	node* back = nullptr;
	node* front = _data[idx];
	while (front) {
		if(front->_value == y) {
			if (!back) {
				back = front->_next;
				_data[idx] = back;
			}
			else {
				back->_next = front->_next;
			}

			delete front;

			break;
		}
		else {
			back = front;
			front = front->_next;
		}

	}
	if (!front) {
		throw HashTableException{ "there is not such element. " };
	}
	--_size;
}

bool HashTable::find(const int y) const
{
	int idx = hash(y);
	node* ptr = _data[idx];
	while (ptr) {
		if (ptr->_value == y) {
			return true;
		}
		ptr = ptr->_next;
	}
	return false;
}

void HashTable::print(int idx) const
{
	node* ptr = _data[idx];
	while (ptr) {
		std::cout << ptr->_value;
		std::cout << ' ';
		ptr = ptr->_next;
	}
}


int HashTable::size() const
{
	return _data.size();
}


unsigned HashTable::hash(const int x) const
{
	unsigned h = ((x >> 16) ^ x) * 0x45d9f3b;
	h = ((h >> 16) ^ h) * 0x45d9f3b;
	h = (h >> 16) ^ h;

	return h;
}

void HashTable::reHashing() {
	std::vector<node*> temp(_data.size() * 2, nullptr);

	for (int i = 0; i < _data.size(); ++i) {
		node* ptr = _data[i];
		while (ptr) {
			int element = ptr->_value;
			int idx = hash(element) % temp.size();
			node* tPtr = new node;
			tPtr->_value = element;
			tPtr->_next = temp[idx];
			temp[idx] = tPtr;
			node* tmp = ptr;
			ptr = ptr->_next;
			delete tmp;
		}
	}

	_data = temp;
}

