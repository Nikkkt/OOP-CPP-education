#include "GraficsCard.h"
#include <iostream>
using namespace std;

GraficsCard::GraficsCard(const GraficsCard& copy): memory(copy.memory), price(copy.price) {
	name = new char[strlen(copy.name) + 1];
	strcpy_s(name, strlen(copy.name) + 1, copy.name);
}

GraficsCard::GraficsCard() :memory(0) {
	name = nullptr;
	price = 0;
}

GraficsCard::GraficsCard(const char* name, int memory, double price) :memory(memory), price(price) {
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

GraficsCard::~GraficsCard() {
	delete[] name;
}

void GraficsCard::Input() {
	char buff[20];
	cout << "Enter name -> ";
	cin.getline(buff, 20);
	this->name = new char[strlen(buff) + 1];
	strcpy_s(this->name, strlen(buff) + 1, buff);
	cout << "Enter price -> ";
	cin >> price;
}

void GraficsCard::Print() {
	printf("Name: %s\nMemory: %d\nPrice: %.02f\n", name, memory, price);
}

// Getters
const char* GraficsCard::GetName() const { return name; }
const int GraficsCard::GetMemory() const { return memory; }
double GraficsCard::GetPrice() const { return price; }

// Setters
void GraficsCard::SetName(const char* name) {
	if (name != nullptr) delete[] name;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}
void GraficsCard::SetPrice(double price) { this->price = price; }