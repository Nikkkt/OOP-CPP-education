#pragma once
class RAM {
private:
	// Fields
	char* name;
	int memory;
	double price;

public:
	// Constructor, destructor
	RAM(const RAM& copy);
	RAM(const char* name, int memory, double price);
	~RAM();

	// Methods
	void Input();
	void Print();

	// Getters
	const char* GetName();
	int GetMemory();
	double GetPrice();

	// Setters
	void SetName(const char* name);
	void SetMemory(int memory);
	void SetPrice(double price);
};