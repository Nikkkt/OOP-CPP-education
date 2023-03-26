#include <iostream>
#include "first.h"
#include "second.h"

int main() {
	Employer* emp[3] = { new President("Nikita"), new Manager("Danya"), new Worker("Maksym") };
	for (int i = 0; i < 3; i++) emp[i]->Show();
	std::cout << std::endl;

	LinearEquation linear(2, 6);
	linear.ShowAnswer();

	QuadraticEquation quadratic(1, 5, 4);
	quadratic.ShowAnswer();

	Equation* eq[2] = { new LinearEquation(4, 8), new QuadraticEquation(1, -3, 2) };
	for (int i = 0; i < 2; i++) eq[i]->ShowAnswer();
}