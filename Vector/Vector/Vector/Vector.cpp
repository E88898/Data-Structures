#include "vector.h"
#include <iostream>

Vector::Vector()
	: _data{ nullptr },
	_size{ 0 },
	_capacity{ 1 }
{
	_data = new int[_capacity];
}

Vector::Vector(int size)
	: _data{ nullptr },
	_size{ size },
	_capacity{ 2 * size }
{
	validateSize();
	_data = new int[_capacity];
}

Vector::Vector(int size, int element)
	: _data{ nullptr },
	_size{ size },
	_capacity{ 2 * size }
{
	validateSize();
	_data = new int[_capacity];
	for (int idx = 0; idx < size; ++idx) {
		_data[idx] = element;
	}
}

Vector::Vector(const Vector& object)
	: _data{ new int[object._capacity] },
	_size{ object._size },
	_capacity{ object._capacity }
{
	for (int idx = 0; idx < _size; ++idx) {
		_data[idx] = object._data[idx];
	}
}

Vector& Vector::operator=(const Vector& object)
{
	if (this == &object) {
		return *this;
	}

	delete[] _data;

	_size = object._size;
	_capacity = object._capacity;
	_data = new int[_capacity];

	for (int idx = 0; idx < _size; ++idx) {
		_data[idx] = object._data[idx];
	}

	return *this;
}

int& Vector::operator[](int index)
{
	if (index >= _size || index < 0) {
		throw VectorException{ "out of bounds index" };
	}
	return _data[index];
}

int Vector::operator[](int index) const
{
	if (index >= _size || index < 0) {
		throw VectorException{ "out of bounds index" };
	}
	return _data[index];
}

void Vector::push_back(int element)
{
	handleFullCondition();
	_data[_size] = element;
	++_size;
}

void Vector::insert(int index, int element)
{
	if (index > _size || index < 0) {
		throw VectorException{ "out of bounds index" };
	}

	handleFullCondition();

	for (int j = _size; j >= index + 1; --j) {
		_data[j] = _data[j - 1];
	}

	_data[index] = element;
	++_size;
}

void Vector::pop_back()
{
	if (empty()) {
		throw VectorException{ "empty vector" };
	}
	--_size;
}

void Vector::remove(int index)
{
	if (index < 0 || index >= _size) {
		throw VectorException{ "invalid index" };
	}
	if (empty()) {
		throw VectorException{ "empty Vector" };
	}

	for (int j = index; j < _size - 1; ++j) {
		_data[j] = _data[j + 1];
	}
	--_size;
}

Vector::~Vector()
{
	delete[] _data;
}

int Vector::getSize() const
{
	return _size;
}

bool Vector::empty() const
{
	return (0 == _size);
}

void Vector::reserve(int number)
{
	if (number > _capacity) {
		_capacity = number;
		int* temp = new int[_capacity];
		for (int idx = 0; idx < _size; ++idx) {
			temp[idx] = _data[idx];
		}
		delete[] _data;
		_data = temp;
	}
}

std::ostream& operator<<(std::ostream& out, const Vector& obj)
{
	for (int idx = 0; idx < obj._size; ++idx) {
		out << obj._data[idx] << ' ';
	}

	return out;
}

std::istream& operator>>(std::istream& input, Vector& obj)
{
	obj.handleFullCondition();
	input >> obj._data[obj._size];
	++(obj._size);

	return input;
}

bool Vector::operator==(const Vector& obj)
{
	if (_size != obj._size) {
		return false;
	}

	for (int idx = 0; idx < _size; ++idx) {
		if (_data[idx] != obj._data[idx]) {
			return false;
		}
	}
	return true;
}

bool Vector::operator!=(const Vector& obj)
{
	if (_size != obj._size) {
		return true;
	}
	
	for (int idx = 0; idx < _size; ++idx) {
		if (_data[idx] != obj._data[idx]) {
			return true;
		}
	}
	return false;

}

bool Vector::operator<(const Vector& obj)
{
	for (int idx = 0; idx < _size; ++idx) {
		if (_data[idx] > obj._data[idx]) {
			return false;
		}
	}
	return true;
}

bool Vector::operator>(const Vector& obj)
{
	for (int idx = 0; idx < _size; ++idx) {
		if (_data[idx] < obj._data[idx]) {
			return false;
		}
	}
	return true;
}

/// helpers
void Vector::validateSize()
{
	if (_size <= 0) {
		std::cerr << "Error: invalid size. " << _size << std::endl;
		VectorException exception{ "invalid size" };
		throw exception;
	}
}

void Vector::handleFullCondition()
{
	if (_size == _capacity) {
		_capacity *= 2;
		int* temp = new int[_capacity];
		for (int idx = 0; idx < _size; ++_size) {
			temp[idx] = _data[idx];
		}
		delete[] _data;
		_data = temp;
	}
}
