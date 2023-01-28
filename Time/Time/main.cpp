#include <iostream>
#include "Time.h"

int main() {
	Time t1(1, 4, 1);
	std::cout << t1 << std::endl;
	Time t2;
	std::cin >> t2;
	std::cout << t2 << std::endl;
}