#pragma once
#include "Carnivore.hpp"

class Continent {
public:
    virtual Herbivore* createHerbivore() = 0;
    virtual Carnivore* createCarnivore() = 0;
};