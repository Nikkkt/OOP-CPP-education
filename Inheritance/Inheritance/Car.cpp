#include "Car.h"
#include <iostream>

Car::Car() {
	speed = 0;
	weightKg = 0;
	price = 0;
}

Car::Car(unsigned int speed, unsigned int weightKg, float price) {
	this->speed = speed;
	this->weightKg = weightKg;
	this->price = price;
}

void Car::setSpeed(unsigned int speed) { this->speed = speed; }

void Car::setWeightKg(unsigned int weightKg) { this->weightKg = weightKg; }

void Car::setPrice(float price) { this->price = price; }

void Car::TimeAndPrice(unsigned int distance) { if (speed != 0) std::cout << "Time: " << (float)distance / (float)speed << " m/s" << std::endl << "Price: " << ((float)distance / (float)speed) * price << "$" << std::endl; }

void Car::ShowWeight() { std::cout << "Weight: " << weightKg << " kg" << std::endl; }