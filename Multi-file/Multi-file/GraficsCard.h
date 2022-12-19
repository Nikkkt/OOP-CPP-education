#pragma once
class GraficsCard {
private:
	// Fields
	char* name;
	const int memory;
	double price;

public:
	// Constructor, destructor
	GraficsCard(const GraficsCard& copy);
	GraficsCard(const char* name, int memory, double price);
	~GraficsCard();

	// Methods
	void Input();
	void Print();

	// Getters
	const char* GetName();
	const int GetMemory();
	double GetPrice();

	// Setters
	void SetName(const char* name);
	void SetPrice(double price);
};
