#include "Bike.h"
#include <iostream>

Bike::Bike() {
	speed = 0;
	weightKg = 0;
	price = 0;
}

Bike::Bike(int speed, unsigned int weightKg, float price) {
	this->speed = speed;
	this->weightKg = weightKg;
	this->price = price;
}

void Bike::setSpeed(unsigned int speed) { this->speed = speed; }
	 
void Bike::setWeightKg(unsigned int weightKg) { this->weightKg = weightKg; }
	
void Bike::setPrice(float price) { this->price = price; }
	
void Bike::TimeAndPrice(unsigned int distance) { if (speed != 0) std::cout << "Time: " << (float)distance / (float)speed << " m/s" << std::endl << "Price: " << ((float)distance / (float)speed) * price << "$" << std::endl; }

void Bike::ShowWeight() { std::cout << "Weight: " << weightKg << " kg" << std::endl; }