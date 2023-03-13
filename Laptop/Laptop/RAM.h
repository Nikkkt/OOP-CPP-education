#pragma once
#include <iostream>

class RAM {
private:
	std::string firm;
	int GB;

public:
	RAM();
	RAM(std::string firm, int GB);

	void Show();
};