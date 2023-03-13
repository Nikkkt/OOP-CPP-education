#include "Carriage.h"
#include <iostream>

Carriage::Carriage() {
	speed = 0;
	weightKg = 0;
	price = 0;
}

Carriage::Carriage(unsigned int speed, unsigned int weightKg, float price) {
	this->speed = speed;
	this->weightKg = weightKg;
	this->price = price;
}

void Carriage::setSpeed(unsigned int speed) { this->speed = speed; }

void Carriage::setWeightKg(unsigned int weightKg) { this->weightKg = weightKg; }

void Carriage::setPrice(float price) { this->price = price; }

void Carriage::TimeAndPrice(unsigned int distance) { if (speed != 0) std::cout << "Time: " << (float)distance / (float)speed << " m/s" << std::endl << "Price: " << ((float)distance / (float)speed) * price << "$" << std::endl; }

void Carriage::ShowWeight() { std::cout << "Weight: " << weightKg << " kg" << std::endl; }