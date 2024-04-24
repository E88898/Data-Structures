#include "String.h"
#include <iostream>

int main()
{
	char temp[] = "brat";
	String s(temp);
	std::cout << s << std::endl;
	String s1 = s;
	std::cout << s1 << std::endl;
	String s2;
	s2 = s1;
	std::cout << s2 << std::endl;
	char temp1[] = "drug";
	String s3(temp1);
	std::cout << s3[3] << std::endl;
	if (s2 == s1) {
		std::cout << "s2 == s1" << std::endl;
	}
	String s4 = s1 + s3;
	std::cout << s4;

	return 0;
}