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
		node* ptr = _data[i];
		while (ptr) {
			node* temp = ptr;
			ptr = ptr->_next;
			delete temp;
		}
	}
}

void HashTable::insert(const int key, const std::string& value) {
	if (_data.size() * loadFactor <= _size) {
		reHashing();
	}
	if (!value.size()) {
		throw HashTableException{ "empty value. " };
	}
	int idx = hash(key) % _data.size();
	node* front = _data[idx];
	while (front) {
		if (front->_value._key == key) {
			throw HashTableException{ "table has a that key. " };
		}
		else {
			front = front->_next;
		}
	}
	node* ptr = new node;
	ptr->_value._key = key;
	ptr->_value._value = value;
	ptr->_next = _data[idx];
	_data[idx] = ptr;
	++_size;
}

void HashTable::remove(const int key) {
	int idx = hash(key) % _data.size();
	node* back = nullptr;
	node* front = _data[idx];
	while (front) {
		if (front->_value._key == key) {
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
		throw HashTableException{ "table has not that key." };
	}
	--_size;
}

pair HashTable::find(const int key) const
{
	int idx = hash(key) % _data.size();
	node* ptr = _data[idx];
	while (ptr) {
		if (ptr->_value._key == key) {
			return ptr->_value;
		}
		ptr = ptr->_next;
	}
	throw HashTableException{ "table has not that key. " };

	return pair();
}

std::string& HashTable::operator[](const int key) const
{
	int idx = hash(key) % _data.size();
	node* ptr = _data[idx];
	while (ptr) {
		if (ptr->_value._key == key) {
			return ptr->_value._value;
		}
		ptr = ptr->_next;
	}
	throw HashTableException{ "table has not that key. " };
	return ptr->_value._value;
}

void HashTable::print(const int idx) const
{
	if (idx < 0 || idx >= _data.size()) {
		throw HashTableException{ "index out of bounds. " };
	}
	node* ptr = _data[idx];
	while (ptr) {
		std::cout << ptr->_value._key << ' ';
		std::cout << ptr->_value._value<< ',';
		std::cout << std::endl;
		ptr = ptr->_next;
	}
}

int HashTable::size() const
{
	return _data.size();
}

unsigned HashTable::hash(const int key) const
{
	unsigned h = ((key >> 16) ^ key) * 0x45d9f3b;
	h = ((h >> 16) ^ h) * 0x45d9f3b;
	h = (h >> 16) ^ h;

	return h;
}

void HashTable::reHashing()
{
	std::vector<node*> temp = { _data.size() * 2, nullptr };
	
	for (int i = 0; i < _data.size(); ++i) {
		node* ptr = _data[i];
		while (ptr) {
			node* del = ptr;
			int idx = hash(ptr->_value._key) % temp.size();
			node* tPtr = new node;
			tPtr->_value._key = ptr->_value._key;
			tPtr->_value._value = ptr->_value._value;
			tPtr->_next = temp[idx];
			temp[idx] = tPtr;
			ptr = ptr->_next;
			delete del;
		}
	}
	_data = temp;
}
