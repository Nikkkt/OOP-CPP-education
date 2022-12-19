#pragma once
class CPU {
private:
	// Fields
	char* name;
	double Ghz;
	double price;

public:
	// Constructor, destructor
	CPU(const CPU& copy);
	CPU(const char* name, double Ghz, double price);
	~CPU();

	// Methods
	void Input();
	void Print();

	// Getters
	const char* GetName();
	double GetGhz();
	double GetPrice();

	// Setters
	void SetName(const char* name);
	void SetGhz(double Ghz);
	void SetPrice(double price);
};