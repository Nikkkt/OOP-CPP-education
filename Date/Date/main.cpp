#include <iostream>
#include "Date.h"

int main() {
	Date d1;
	std::cout << d1 << std::endl; // 00.00.0
	std::cin >> d1;
	std::cout << d1 << std::endl;

	Date d2;
	std::cin >> d2;
	std::cout << d2 << std::endl;
}