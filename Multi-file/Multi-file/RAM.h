#pragma once
class RAM {
private:
	// Fields
	char* name;
	int memory;
	double price;

	RAM(const char* name);
	RAM(const char* name, int memory);

public:
	// Constructor, destructor
	RAM(const RAM& copy);
	RAM();
	RAM(const char* name, int memory, double price);
	~RAM();

	// Methods
	void Input();
	void Print();

	// Getters
	const char* GetName() const;
	int GetMemory() const;
	double GetPrice() const;

	// Setters
	void SetName(const char* name);
	void SetMemory(int memory);
	void SetPrice(double price);
};