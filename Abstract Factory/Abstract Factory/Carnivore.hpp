#pragma once
#include "Herbivore.hpp"

class Carnivore {
protected:
	double Power;
	int herbivoresEaten;

public:
	virtual void Eat(Herbivore* herbivore) = 0;
	virtual std::string ToString() = 0;
};