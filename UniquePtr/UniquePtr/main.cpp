#include <iostream>
#include "Fraction.hpp"
#include "Functions.hpp"

int main() {
	auto ptr = std::unique_ptr<Fraction>(new Fraction(7, 9));
	printFraction(ptr.get());

	//ptr does not destroy and we can use it later
	Fraction* ptr2 = ptr.get();
	printFraction(ptr2);
}