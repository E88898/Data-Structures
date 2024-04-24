#include "ForwardList.h"

int main() {

	ForwardList l;
	l.push_front(2);
	std::cout << l.size() << std::endl;
	try {
		l.print(1);
	}
	catch (ListException& e) {
		std::cout << e << std::endl;
	}
	for (int i = 0; i < 6; ++i) {
		l.push_front(i);
	}

	l.push_back(10);

	l.insert_after(l.getNode(5), 55);

	for (int i = 0; i < l.size(); ++i) {
		l.print(i);
		std::cout << ' ';
	}
	return 0;
}