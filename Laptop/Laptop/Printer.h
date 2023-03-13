#pragma once
#include <iostream>

class Printer {
private:
	std::string firm;
	int PrintSpeed;

public:
	Printer();
	Printer(std::string firm, int PrintSpeed);

	void Show();
};