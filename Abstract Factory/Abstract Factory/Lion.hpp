#pragma once
#include "Carnivore.hpp"

class Lion : public Carnivore {
public:
	Lion() {
		Power = 600;
		herbivoresEaten = 0;
	}
	void Eat(Herbivore* herbivore) {
		if (herbivore->IsAlive()) {
			if (Power >= herbivore->GetWeight()) {
				std::cout << "Lion has ate " << herbivore->GetName() << std::endl;
				Power += 25;
				herbivoresEaten++;
				herbivore->Die();
			}
			else {
				std::cout << "Lion has tried eat " << herbivore->GetName() << std::endl;
				Power -= 25;
			}
		}
	}
	std::string ToString() {
		std::stringstream s;
		s << std::boolalpha << "Lion" << std::endl << "Power: " << Power << std::endl << "Herbivores eaten: " << herbivoresEaten << std::endl;
		return s.str();
	}
};