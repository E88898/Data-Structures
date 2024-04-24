#include "Heap.h"
#include <iostream>
#include <vector>

void heapSort(int* arr, int size) {
	int* ptr = arr;
	int count = 0;
	Heap h;
	while (count != size) {
		h.insert(*ptr);
		++ptr;
		++count;
	}

	std::vector<int> temp(size);
	int idx = size - 1;
	for (int i = 0; i < size; ++i) {
		temp[idx] = h.root();
		h.remove();
		--idx;
	}
	ptr = arr;
	for (int i = 0; i < size; ++i) {
		*ptr = temp[i];
		++ptr;
	}
}

int main() {
	int arr[] = {2,5,3,20,14,100,24,1444,-2};
	int size = sizeof(arr) / sizeof(arr[0]);
	heapSort(arr, size);
	for (int i = 0; i < size; ++i) {
		std::cout << arr[i] << ' ';
	}

	return 0;
}