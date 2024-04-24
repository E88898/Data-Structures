#include "Queue.h"

int main() {

	Queue q(1, 5);
	for (int i = 2; i <= 5; ++i) {
		q.push(i);
	}

	try {
		q.push(10);
	}
	catch (QueueException& e) {
		std::cout << e << std::endl;
	}

	for (int i = 0; i < q.size(); ++i) {
		std::cout << q[i] << ' ';
	}
	std::cout << std::endl;

	Queue t;
	try {
		t.pop();
	}
	catch (QueueException& e) {
		std::cout << e << std::endl;
	}

	Queue c(2,7);
	c.push(5);
	std::cout << c.size() << std::endl;

	try {
		Queue f(1, 0);
	}
	catch (QueueException& e) {
		std::cout << e << std::endl;
	}

	std::cout << q.front() << ' ' << q.back() << std::endl;

		
	return 0;
}