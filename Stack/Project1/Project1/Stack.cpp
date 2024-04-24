#include "Stack.h"

Stack::Stack()
{	
}

Stack::Stack(int num)
	:_data{num}
{
}

void Stack::push(int num) {
	_data.push_back(num);
}

void Stack::pop() {
	if (empty()) {
		throw StackException{ "empty stack" };
	}
	else {
		_data.pop_back();
	}
}

int Stack::top() {
	return _data[_data.size() - 1];
}

int Stack::size() {
	return _data.size();
}

bool Stack::empty() {
	
	if (0 == _data.size()) {
		return true;
	}
	return false;
}

int Stack::operator[](int idx)
{
	if (idx < 0 || idx > _data.size() - 1) {
		throw StackException{ "out of bounds index" };
	}
	return _data[idx];
}

std::ostream& operator<<(std::ostream& out, const StackException& obj)
{
	out << obj.s;
	return out;
}
