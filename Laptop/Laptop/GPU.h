#pragma once
#include <iostream>

class GPU {
private:
	std::string firm;
	int GB;

public:
	GPU();
	GPU(std::string firm, int GB);

	void Show();
};