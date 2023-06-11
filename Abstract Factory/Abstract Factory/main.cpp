#include "Animalworld.hpp"
#include "Africa.hpp"
#include "NorthAmerica.hpp"
#include "Eurasia.hpp"

int main() {
	Continent* eurasia = new Eurasia();
	AnimalWorld biosphere(eurasia);

	for (int i = 0; i < 3; i++) {
		biosphere.AddHerbivore();
		biosphere.AddCarnivore();
	}

	biosphere.MealsHerbivores();
	std::cout << std::endl;
	biosphere.NutritionCarnivores();
	std::cout << std::endl;

	biosphere.Print();

	delete eurasia;

	Continent* africa = new Africa();
	AnimalWorld biosphere2(africa);

	for (int i = 0; i < 3; i++) {
		biosphere2.AddHerbivore();
		biosphere2.AddCarnivore();
	}

	biosphere2.MealsHerbivores();
	std::cout << std::endl;
	biosphere2.NutritionCarnivores();
	std::cout << std::endl;

	biosphere2.Print();

	delete africa;

	Continent* northAmerica = new NorthAmerica();
	AnimalWorld biosphere3(northAmerica);

	for (int i = 0; i < 3; i++) {
		biosphere3.AddHerbivore();
		biosphere3.AddCarnivore();
	}

	biosphere3.MealsHerbivores();
	std::cout << std::endl;
	biosphere3.NutritionCarnivores();
	std::cout << std::endl;

	biosphere3.Print();

	delete northAmerica;
}
