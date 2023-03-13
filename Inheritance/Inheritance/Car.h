#pragma once
#include "Transport.h"

class Car : public Transport {
public:
	Car();
	Car(unsigned int speed, unsigned int weightKg, float price);

	void setSpeed(unsigned int speed);
	void setWeightKg(unsigned int weightKg);
	void setPrice(float price);

	void TimeAndPrice(unsigned int distance);
	void ShowWeight();
};