#pragma once
#include "Continent.hpp"
#include "Wildebeest.hpp"
#include "Lion.hpp"

class Africa : public Continent {
public:
	Herbivore* createHerbivore() { return new Wildebeest(); }
	Carnivore* createCarnivore() { return new Lion(); }
};