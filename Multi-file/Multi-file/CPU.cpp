#include "CPU.h"
#include <iostream>
using namespace std;

CPU::CPU(const CPU& copy): Ghz(copy.Ghz), price(price) {
	name = new char[strlen(copy.name) + 1];
	strcpy_s(name, strlen(copy.name) + 1, copy.name);
}

CPU::CPU() {
	name = nullptr;
	Ghz = 0.0;
	price = 0.0;
}

CPU::CPU(const char* name) {
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

CPU::CPU(const char* name, double Ghz): CPU(name) { this->Ghz = Ghz; }
CPU::CPU(const char* name, double Ghz, double price): CPU(name, Ghz) { this->price = price; }

CPU::~CPU() {
	delete[] name;
}

void CPU::Input() {
	char buff[20];
	cout << "Enter name -> ";
	cin.getline(buff, 20);
	this->name = new char[strlen(buff) + 1];
	strcpy_s(this->name, strlen(buff) + 1, buff);

	cout << "Enter Ghz -> ";
	cin >> Ghz;

	cout << "Enter price -> ";
	cin >> price;
}

void CPU::Print() {
	printf("Name: %s\nGhz: %.02f\nPrice: %.02f\n", name, Ghz, price);
}

// Getters
const char* CPU::GetName() const { return name; }
double CPU::GetGhz() const { return Ghz; }
double CPU::GetPrice() const { return price; }

// Setters
void CPU::SetName(const char* name) {
	if (name != nullptr) delete[] name;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}
void CPU::SetGhz(double Ghz) { this->Ghz = Ghz; }
void CPU::SetPrice(double price) { this->price = price; }