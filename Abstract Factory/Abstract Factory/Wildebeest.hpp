#pragma once
#include "Herbivore.hpp"

class Wildebeest : public Herbivore {
public:
	Wildebeest() {
		Weight = 200;
		Life = true;
	}
	void EatGrass() {
		std::cout << "Wildebeest has ate" << std::endl;
		Weight += 5;
	}
	void Die() {
		std::cout << "Wildebeest die" << std::endl;
		Life = false;
	}
	std::string GetName() { return "Wildebeest"; }
	std::string ToString() {
		std::stringstream s;
		s << std::boolalpha << "Wildebeest" << std::endl << "Weight: " << Weight << std::endl << "Alive: " << Life << std::endl;
		return s.str();
	}
};