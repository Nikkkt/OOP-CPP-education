#include <iostream>
#include "pc.hpp"
#include "house.hpp"
using namespace std;

int main() {
	// Classwork
	Creator* creators[3];
	creators[0] = new CreatorHomePC();
	creators[1] = new CreatorOfficePC();
	creators[2] = new CreatorGamePC();
	Factory(creators, 3);
	cout << endl;

	// Homework
	Developer* developer = new PanelDeveloper();
	House* house = Client(developer);
	delete house;
	delete developer;

	developer = new WoodDeveloper();
	house = Client(developer);
	delete house;
	delete developer;

	developer = new BrickDeveloper();
	house = Client(developer);
	delete house;
	delete developer;
}