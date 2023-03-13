#pragma once
#include <iostream>

class CPU {
private:
	std::string firm;
	float GHz;

public:
	CPU();
	CPU(std::string firm, float GHz);

	void Show();
};