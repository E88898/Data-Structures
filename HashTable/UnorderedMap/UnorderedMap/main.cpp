#include <iostream>
#include "HashTable.h"

int main() {

	HashTable h;
	h.insert(0, "dda");
	h.insert(1, "ddb");
	h.insert(2, "ddc");
	h.insert(3, "ddd");
	h.insert(4, "dde");

	for (int i = 0; i < h.size(); ++i) {
		std::cout << i << ") ";
		h.print(i);
		std::cout << std::endl;
	}

	h[3] = "sok";
	std::cout << std::endl;
	std::cout << h.find(3)._value;
	std::cout << std::endl;

	try {
		h.remove(5);
	}
	catch (HashTable::HashTableException& e) {
		e.what();
	}

	return 0;
}