#pragma once
#include "Continent.hpp"
#include "Elk.hpp"
#include "Tiger.hpp"

class Eurasia : public Continent {
public:
    Herbivore* createHerbivore() { return new Elk(); }
    Carnivore* createCarnivore() { return new Tiger(); }
};