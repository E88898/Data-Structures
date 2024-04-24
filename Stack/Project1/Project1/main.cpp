#include "Stack.h"

int main() {
	Stack s;
	try {
		s.pop();
	}
	catch (StackException& exc) {
		std::cout << exc << std::endl;
	}
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(0);
	std::cout << s.size() << std::endl;
	std::cout << s.top() << std::endl;
	try {
		s[8];
	}
	catch (StackException& exc) {
		std::cout << exc << std::endl;
	}

	return 0;
}