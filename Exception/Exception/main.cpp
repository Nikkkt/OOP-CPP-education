#include <iostream>
#include "funclions.hpp"

int main() {
	try {
		int number;
		std::cout << "Enter a number: ";
		std::cin >> number;
		std::cout << std::boolalpha << "Is a number lucky: " << isALuckyNumber(number) << std::endl;
	}
	catch (const char* str) { std::cout << "Error: " << str << std::endl; }
	catch (const std::exception& ex) { std::cout << "Error: " << ex.what() << std::endl; }
	catch (...) { std::cout << "Error: Something went wrong..." << std::endl; }
}