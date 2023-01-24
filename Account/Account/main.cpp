#include <iostream>
#include "Account.h"

int main() {
	Account pers1("Nikita", "Terpilovskyi", 1326292219, 3.5, 37463.56);
	std::cout << pers1 << std::endl;
	std::cout << std::endl;

	pers1.changeOfOwnership("Vladislav", "Kolisnik");
	pers1.showInfo();
	std::cout << std::endl;

	pers1.withdrawMoney(10000);
	pers1.showInfo();
	std::cout << std::endl;

	pers1.addMoney(17283.46);
	pers1.showInfo();
	std::cout << std::endl;

	pers1.addPercents(4.89);
	pers1.showInfo();
	std::cout << std::endl; 

	double euro = pers1.toUSD();
	std::cout << euro << std::endl; 

	double dollar = pers1.toEUR();
	std::cout << dollar << std::endl;
}