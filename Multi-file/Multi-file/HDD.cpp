// Файл реализации
#include "HDD.h"
#include <iostream>
using namespace std;

HDD::HDD(const HDD& copy): memory(copy.memory), price(copy.price) {
	name = new char[strlen(copy.name) + 1];
	strcpy_s(name, strlen(copy.name) + 1, copy.name);
}

HDD::HDD(const char* name, int memory, double price):memory(memory),price(price) {
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

HDD::~HDD() {
	delete[] name;
}

void HDD::Input() {
	char buff[20];
	cout << "Enter name -> ";
	cin.getline(buff, 20);
	this->name = new char[strlen(buff) + 1];
	strcpy_s(this->name, strlen(buff) + 1, buff);
	cout << "Enter price -> ";
	cin >> price;
}

void HDD::Print() {
	printf("Name: %s\nMemory: %d\nPrice: %.02f\n", name, memory, price);
}

// Getters
const char* HDD::GetName() { return name; }
const int HDD::GetMemory() { return memory; }
double HDD::GetPrice() { return price; }

// Setters
void HDD::SetName(const char* name) {
	if (name != nullptr) delete[] name;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}
void HDD::SetPrice(double price) { this->price = price; }