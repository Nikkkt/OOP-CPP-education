#include "RAM.h"
#include <iostream>
using namespace std;

RAM::RAM(const RAM& copy): memory(copy.memory), price(copy.price) {
	name = new char[strlen(copy.name) + 1];
	strcpy_s(name, strlen(copy.name) + 1, copy.name);
}

RAM::RAM() {
	name = nullptr;
	memory = 0;
	price = 0.0;
}

RAM::RAM(const char* name) {
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

RAM::RAM(const char* name, int memory): RAM(name) {
	this->memory = memory;
}

RAM::RAM(const char* name, int memory, double price): RAM(name, memory) {
	this->price = price;
}

RAM::~RAM() {
	delete[] name;
}

void RAM::Input() {
	char buff[20];
	cout << "Enter name -> ";
	cin.getline(buff, 20);
	this->name = new char[strlen(buff) + 1];
	strcpy_s(this->name, strlen(buff) + 1, buff);

	cout << "Enter memory -> ";
	cin >> memory;

	cout << "Enter price -> ";
	cin >> price;
}

void RAM::Print() {
	printf("Name: %s\nMemory: %d\nPrice: %.02f\n", name, memory, price);
}

// Getters
const char* RAM::GetName() const { return name; }
int RAM::GetMemory() const { return memory; }
double RAM::GetPrice() const { return price; }

// Setters
void RAM::SetName(const char* name) {
	if (name != nullptr) delete[] name;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}
void RAM::SetMemory(int memory) { this->memory = memory; }
void RAM::SetPrice(double price) { this->price = price; }