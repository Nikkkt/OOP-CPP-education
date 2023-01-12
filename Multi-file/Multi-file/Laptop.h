#pragma once
#include "GraficsCard.h"
#include "CPU.h"
#include "RAM.h"
#include "HDD.h"

class Laptop {
private:
	char* name;
	GraficsCard gc;
	CPU c;
	RAM r;
	HDD h;
	double price;

public:
	// Constructor, destructor
	Laptop(const Laptop& copy);
	Laptop();
	Laptop(const char* name, GraficsCard& gc, CPU& c, RAM& r, HDD& h);
	~Laptop();

	// Methods
	void Input();
	void Print();

	// Getters
	const char* getName() const;
	HDD getHDD() const;
	GraficsCard getGraficsCard() const;
	CPU getCPU() const;
	RAM getRAM() const;
	double getPrice() const;

	// Setters
	void setName(char* name);
	void setHDD(HDD h);
	void setGraficsCard(GraficsCard gc);
	void setCPU(CPU c);
	void setRAM(RAM r);
};