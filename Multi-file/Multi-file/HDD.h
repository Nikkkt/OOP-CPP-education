// Файл дизайна
#pragma once
class HDD {
private:
	// Fields
	char* name;
	const int memory;
	double price;

public:
	// Constructor, destructor
	HDD(const HDD& copy);
	HDD(const char* name, int memory, double price);
	~HDD();

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