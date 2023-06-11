#pragma once
#include "Herbivore.hpp"

class Elk : public Herbivore {
public:
    Elk() {
        Weight = 540;
        Life = true;
    }
    void EatGrass() {
        std::cout << "Elk has ate" << std::endl;
        Weight += 5;
    }
    void Die() {
        std::cout << "Elk die" << std::endl;
        Life = false;
    }
    std::string GetName() { return "Elk"; }
    std::string ToString() {
        std::stringstream s;
        s << std::boolalpha << "Elk" << std::endl << "Weight: " << Weight << std::endl << "Alive: " << Life << std::endl;
        return s.str();
    }
};