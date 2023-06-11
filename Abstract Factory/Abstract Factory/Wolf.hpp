#pragma once
#include "Carnivore.hpp"

class Wolf : public Carnivore {
public:
	Wolf() {
		Power = 600;
		herbivoresEaten = 0;
	}
	void Eat(Herbivore* herbivore) {
		if (herbivore->IsAlive()) {
			if (Power >= herbivore->GetWeight()) {
				std::cout << "Wolf has ate " << herbivore->GetName() << std::endl;
				Power += 20;
				herbivoresEaten++;
				herbivore->Die();
			}
			else {
				std::cout << "Wolf has tried eat " << herbivore->GetName() << std::endl;
				Power -= 20;
			}
		}
	}
	std::string ToString() {
		std::stringstream s;
		s << std::boolalpha << "Wolf" << std::endl << "Power: " << Power << std::endl << "Herbivores eaten: " << herbivoresEaten << std::endl;
		return s.str();
	}
};