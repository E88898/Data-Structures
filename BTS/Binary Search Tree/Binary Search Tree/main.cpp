#include "BTS.h"
#include <iostream>

int main() {

	BTS t;
	t.insert(10);
	t.insert(4);
	t.insert(16);
	t.insert(2);
	t.insert(8);
	t.insert(13);
	t.insert(24);
	t.insert(1);
	t.insert(5);
	t.insert(9);
	t.insert(18);
	t.insert(27);
	t.insert(7);
	t.insert(19);
	t.insert(30);

													/*
														10
													  /	   \
													4		 16
												  /	  \     /   \
											    2       8  13     24
										      /		   / \       /  \
										    1		  5   9    18    27
													   \         \     \
													     7        19    30

													*/
	try {
		t.remove(22);
	}
	catch (BTSException e) {
		e.what();
		std::cout << std::endl;
	}
	t.remove(10);
	std::cout << "count of nodes " << t.getSize();
	std::cout << std::endl;
	t.levelorderT(t.getRoot());
	if (t.find(13)) {
		std::cout << std::endl;
		std::cout << "ok";
	}
}