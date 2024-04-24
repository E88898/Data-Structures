#include "HashTable.h"
#include <iostream>

int main() {

	HashTable h;
	for (int i = 0; i < 5; ++i) {
		h.insert(i);
	}

	for (int i = 0; i < h.size(); ++i) {
		std::cout << i << ") ";
		h.print(i);
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << h.size();
	return 0;
}