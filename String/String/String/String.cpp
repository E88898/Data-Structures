#include "String.h"
#include <iostream>
#include <cstring>

String::String()
	:_length{ 0 },
	_data{ new char[_length + 1] }
{
	_data[0] = '\0';
}

String::String(const char* string)
{
	if (!string)
	{
		_length = 0;
		_data = new char[0];
	}
	else
	{
		_length = strlen(string);
		_data = new char[_length + 1];
		for (int idx = 0; idx < _length; ++idx) {
			_data[idx] = string[idx];
		}
		_data[_length] = '\0';
	}
}

String::String(const String& other)
	:_length{ other._length },
	_data{ new char[_length + 1] }
{
	for (int idx = 0; idx <= _length; ++idx) {
		_data[idx] = other._data[idx];
	}
}

String& String::operator=(const String& other)
{
	if (this == &other) {
		return *this;
	}
	delete[] _data;
	_length = other._length;
	_data = new char[_length + 1];
	for (int idx = 0; idx <= _length; ++idx) {
		_data[idx] = other._data[idx];
	}
	return *this;
}

String::~String()
{
	delete[] _data;
}

char& String::operator[](int index)
{
	if (index < 0 || index >= _length) {
		
	}
	return _data[index];
}

char String::operator[](int index) const
{
	if (index < 0 || index >= _length) {
		

	}
	return _data[index];
}

String String::operator+(const String& other) const
{
	int totalLength = _length + other._length;
	char* temp = new char[totalLength + 1];
	for (int idx = 0; idx < _length; ++idx) {
		temp[idx] = _data[idx];
	}
	int tempIdx = 0;
	for (int idx = _length; idx < totalLength; ++idx) {
		temp[idx] = other._data[tempIdx];
		++tempIdx;
	}
	temp[totalLength] = '/0';
	return temp;
}

String& String::operator+=(const String& other)
{
	if (this != &other) {
		int totalLength = _length + other._length;
		char* temp = new char[totalLength + 1];
		for (int idx = 0; idx < _length; ++idx) {
			temp[idx] = _data[idx];
		}
		int tempIdx = 0;
		for (int idx = _length; idx < totalLength; ++idx) {
			temp[idx] = other._data[tempIdx];
			++tempIdx;
		}
		temp[totalLength] = '/0';
		delete[] _data;
		_length = totalLength;
		_data = temp;
		return *this;
	}
}

bool String::operator==(const String& other)
{
	if (_length != other._length) {
		return false;
	}
	for (int idx = 0; idx < _length; ++idx) {
		if (_data[idx] != other._data[idx]) {
			return false;
		}
	}
	return true;
}

int String::getLength() const
{
	return _length;
}

std::ostream& operator<<(std::ostream& out, const String& object)
{
	out << object._data;
	return out;
}
