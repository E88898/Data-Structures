#include "Heap.h"

Heap::Heap()
{
	_data.push_back(0);
}

void Heap::insert(int value)
{
	_data.push_back(value);
	int idx = _data.size() - 1;
	while (_data[idx] > _data[idx / 2] && idx > 1) {
		int temp = _data[idx];
		_data[idx] = _data[idx / 2];
		_data[idx / 2] = temp;
		idx /= 2;
	}
}

void Heap::remove()
{
	if (_data.size() == 1) {
		return;
	}

	int idx = _data.size() - 1;
	_data[1] = _data[idx];
	_data.pop_back();
	idx = 1;
	while (idx * 2 < _data.size() - 1) {
		if (_data[2 * idx] > _data[2 * idx + 1]) {
			swap(_data[2 * idx], _data[idx]);
			idx = 2 * idx;
		}
		else {
			swap(_data[2 * idx + 1], _data[idx]);
			idx = 2 * idx + 1;
		}
	}

}


int Heap::root() const {
	return _data[1];
}

void Heap::swap(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}
