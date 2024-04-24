#include <iostream>
#include "vector.h"

int main()
{
	Vector v1(4);
	Vector v2(6, 2);
	v1 = v2;
	std::cout << "v1 = " << v1 << std::endl;
	std::cout << "v2 = " << v2 << std::endl;
	Vector v3(3, 4);
	if (v3 > v2) {
		std::cout << "v3 = " << v3 << std::endl;
		std::cout << "v3 > v2" << std::endl;
	}

	Vector v4 = v3;
	std::cout << "v4 = v3 = " << v4 << std::endl;
	v4.push_back(5);
	std::cout << "v4 push_back(5) = " << v4 << std::endl;
	v3.insert(1, 8);
	std::cout << "v3 after inserting 1index 8 element = " << v3 << std::endl;

	Vector v5;
	std::cout << "Enter v5 number: ";
	std::cin >> v5;
	std::cout << "v5 = " << v5 << std::endl;
	try {
		v1[6];
	}
	catch (...) {
		std::cout << "catched exception" << std::endl;
		}
	std::cout << "Enter v4 number: ";
	std::cin >> v4;
	std::cout << "v4 = " << v4 << std::endl;
	return 0;
}