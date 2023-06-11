#pragma once
#include "Carnivore.hpp"

class Tiger : public Carnivore {
public:
    Tiger() {
        Power = 750;
        herbivoresEaten = 0;
    }
	void Eat(Herbivore* herbivore) {
		if (herbivore->IsAlive()) {
			if (Power >= herbivore->GetWeight()) {
				std::cout << "Tiger has ate " << herbivore->GetName() << std::endl;
				Power += 50;
				herbivoresEaten++;
				herbivore->Die();
			}
			else {
				std::cout << "Tiger has tried eat " << herbivore->GetName() << std::endl;
				Power -= 50;
			}
		}
	}
	std::string ToString() {
		std::stringstream s;
		s << std::boolalpha << "Tiger" << std::endl << "Power: " << Power << std::endl << "Herbivores eaten: " << herbivoresEaten << std::endl;
		return s.str();
	}
};