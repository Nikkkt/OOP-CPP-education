#pragma once
class CPU {
private:
	// Fields
	char* name;
	double Ghz;
	double price;

	CPU(const char* name);
	CPU(const char* name, double Ghz);

public:
	// Constructor, destructor
	CPU(const CPU& copy);
	CPU();
	CPU(const char* name, double Ghz, double price);
	~CPU();

	// Methods
	void Input();
	void Print();

	// Getters
	const char* GetName() const;
	double GetGhz() const;
	double GetPrice() const;

	// Setters
	void SetName(const char* name);
	void SetGhz(double Ghz);
	void SetPrice(double price);
};