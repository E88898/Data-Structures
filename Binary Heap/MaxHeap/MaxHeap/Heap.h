#ifndef HEAP_H
#define HEAP_H

#include <vector>

class Heap {
public:
	Heap();
	void insert(int value);
	void remove();
	int root() const;
private:
	std::vector<int> _data;
	void swap(int& x, int& y);
};

#endif
