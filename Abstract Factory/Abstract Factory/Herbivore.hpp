#pragma once
#include <iostream>
#include <vector>
#include <sstream>

class Herbivore {
protected:
	double Weight;
	bool Life;

public:
	double GetWeight() { return Weight; }
	double IsAlive() { return Life; }

	virtual void EatGrass() = 0;
	virtual void Die() = 0;

	virtual std::string GetName() = 0;
	virtual std::string ToString() = 0;
};