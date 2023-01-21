#include <iostream>
#include "Date.h"

int main() {
	Date d1;
	d1.Print(); // 00.00.0000
	d1.Init();
	d1.Print();

	Date d2;
	d2.Init();

	std::cout << (d1 < d2) << std::endl; // test
}