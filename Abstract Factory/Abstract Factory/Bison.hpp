#pragma once
#include "Herbivore.hpp"

class Bison : public Herbivore {
public:
	Bison() {
		Weight = 725;
		Life = true;
	}
	void EatGrass() {
		std::cout << "Bison has ate" << std::endl;
		Weight += 5;
	}
	void Die() {
		std::cout << "Bison die" << std::endl;
		Life = false;
	}
	std::string GetName() { return "Bison"; }
	std::string ToString() {
		std::stringstream s;
		s << std::boolalpha << "Bison" << std::endl << "Weight: " << Weight << std::endl << "Alive: " << Life << std::endl;
		return s.str();
	}
};