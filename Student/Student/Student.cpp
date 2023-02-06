#include "Student.h"
#include <iostream>

Student::Student() {
	name = nullptr;
	rates = nullptr;
	length = 0;
}

Student::Student(const char* name, int* rates, int length): length(length) {
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);

	this->rates = new int[length];
	for (int i = 0; i < length; i++) this->rates[i] = rates[i];
}

Student::Student(const Student& copy): length(copy.length) {
	if (name != nullptr) delete[] name;
	name = new char[strlen(copy.name) + 1];
	strcpy_s(name, strlen(copy.name) + 1, copy.name);

	if (rates != nullptr) delete[] rates;
	rates = new int[length];
	for (int i = 0; i < length; i++) rates[i] = copy.rates[i];
}

Student::~Student() {
	delete[] name;
	delete[] rates;
}

void Student::setName(const char* name) {
	if (this->name != nullptr) delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

void Student::setRates(int* rates) {
	if (this->rates != nullptr) delete[] this->rates;
	this->rates = new int[length];
	for (int i = 0; i < length; i++) this->rates[i] = rates[i];
}

void Student::setLength(int length) { this->length = length; }

const char* Student::getName() const { return name; }
int* Student::getRates() const { return rates; }
int Student::getLength() const { return length; }

void Student::Print() {
	std::cout << "Name: " << name << std::endl << "Rates: ";
	for (int i = 0; i < length; i++) std::cout << rates[i] << " ";
	std::cout << std::endl;
}

Student& Student::operator=(const Student& orig) {
	if (&orig != this) {
		setName(orig.name);
		setRates(orig.rates);
	}
	return *this;
}