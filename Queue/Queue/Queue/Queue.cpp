#include "Queue.h"

Queue::Queue()
	:_data{nullptr},
	_front{ -1 },
	_back{ -1 },
	_capacity{1},
	_itemCount{0}
{
	_data = new int[_capacity];
}

Queue::Queue(const int num, const int capacity)
	:_data{nullptr},
	_front{0},
	_back{0},
	_capacity{1},
	_itemCount{0}
{
	if (validCapacity(capacity)) {
		_capacity = capacity;
	}
	else {
		throw QueueException{ "capacity < 1" };
	}
	_data = new int[_capacity];
	_data[_back] = num;
	++_itemCount;
}

Queue::Queue(const Queue& obj)
	:_data{nullptr},
	_front{obj._front},
	_back{obj._back},
	_capacity{obj._capacity},
	_itemCount{obj._itemCount}
{
	_data = new int[_capacity];
	for (int i = 0; i < _capacity; ++i) {
		_data[i] = obj._data[i];
	}
}

Queue& Queue::operator=(const Queue& obj)
{
	if (this == &obj) {
		return *this;
	}
	delete[] _data;

	_data = new int[obj._capacity];
	_front = obj._front;
	_back = obj._back;
	_capacity = obj._capacity;
	_itemCount = obj._itemCount;

	for (int i = 0; i < _capacity; ++i) {
		_data[i] = obj._data[i];
	}

	return *this;
}

Queue::~Queue()
{
	delete[] _data;
}

void Queue::push(int num)
{
	if (isEmpty()) {
		_front = 0;
		_back = 0;
	}
	else if (isFull()) {
		throw QueueException{ "full queue. " };
	}
	else {
		_back = (_back + 1) % _capacity;
	}
	_data[_back] = num;
	++_itemCount;
}

void Queue::pop()
{
	int x = 0;
	if (isEmpty()) {
		throw QueueException{ "empty queue. " };
	}
	else if (_front == _back) {
		x = _data[_front];
		_front = _back = -1;
	}
	else {
		x = _data[_front];
		_front = (_front + 1) % _capacity;
	}
	--_itemCount;
	
}

int Queue::front() const
{
	return _data[_front];
}

int Queue::back() const
{	
	return _data[_back];
}

bool Queue::isEmpty() const
{
	if (-1 == _front && -1 == _back) {
		return true;
	}
	else {
		return false;
	}
}

int Queue::size() const
{
	return _itemCount;

}

int Queue::operator[](const int idx) const
{
	if (idx > _itemCount) {
		throw QueueException{ "index out of bounds. " };
	}
	return _data[idx];
}

bool Queue::isFull() const
{
	if ((_back + 1) % _capacity == _front) {
		return true;
	}
	return false;
}

bool Queue::validCapacity(const int capacity) const
{
	if (capacity < 1) {
		return false;
	}
	return true;
}

std::ostream& operator<<(std::ostream& out, QueueException& obj)
{
	out << obj.s;
	return out;
}
