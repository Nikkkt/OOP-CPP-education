#pragma once
#include "Continent.hpp"
#include "Bison.hpp"
#include "Wolf.hpp"

class NorthAmerica : public Continent {
public:
	Herbivore* createHerbivore() { return new Bison(); }
	Carnivore* createCarnivore() { return new Wolf(); }
};