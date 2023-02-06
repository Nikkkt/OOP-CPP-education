#pragma once
class Student {
private:
	char* name;
	int* rates;
	int length;

public:
	Student();
	Student(const char* name, int* rates, int length);
	Student(const Student& copy);
	~Student();

	// Setters
	void setName(const char* name);
	void setRates(int* rates);
	void setLength(int length);

	// Getters
	const char* getName() const;
	int* getRates() const;
	int getLength() const;

	void Print();

	Student& operator = (const Student& orig);
};