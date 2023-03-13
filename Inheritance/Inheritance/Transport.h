#pragma once
class Transport {
protected:
	unsigned int speed;
	unsigned int weightKg;
	float price;

public:
	Transport();
	Transport(unsigned int speed, unsigned int weightKg, float price);
};