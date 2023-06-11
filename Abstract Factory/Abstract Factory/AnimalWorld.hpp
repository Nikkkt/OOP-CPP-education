#pragma once
#include "Continent.hpp"

class AnimalWorld {
private:
	Continent* continent;
	std::vector<Herbivore*> herbivores;
	std::vector<Carnivore*> carnivores;

public:
	AnimalWorld(Continent* continent): continent(continent) {
		herbivores.push_back(continent->createHerbivore());
		carnivores.push_back(continent->createCarnivore());
	}

	void AddHerbivore(Herbivore* herbivore = nullptr) {
		if (herbivore != nullptr) herbivores.push_back(herbivore);
		else herbivores.push_back(continent->createHerbivore());
	}
	void AddCarnivore(Carnivore* carnivore = nullptr) {
		if (carnivore != nullptr) carnivores.push_back(carnivore);
		else carnivores.push_back(continent->createCarnivore());
	}

	void MealsHerbivores() { for (int i = 0; i < herbivores.size() * 2; i++) herbivores[rand() % (herbivores.size() - 1)]->EatGrass(); }
	void NutritionCarnivores() { for (auto& carnivore : carnivores) carnivore->Eat(herbivores[rand() % (herbivores.size() - 1)]); }

	void Print() {
		std::cout << "Herbivores:" << std::endl << std::endl;
		for (auto& herbivore : herbivores) std::cout << herbivore->ToString() << std::endl;

		std::cout << "Carnivores:" << std::endl << std::endl;
		for (auto& carnivore : carnivores) std::cout << carnivore->ToString() << std::endl;
	}

	~AnimalWorld() {
		for (auto& elem : herbivores) delete elem; 
		for (auto& elem : carnivores) delete elem;
	}
};