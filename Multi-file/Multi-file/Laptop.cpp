#include "Laptop.h"
#include <iostream>
using namespace std;

Laptop::Laptop(const Laptop& copy): gc(copy.gc), c(copy.c), r(copy.r), h(copy.h), price(copy.price) {
	name = new char[strlen(copy.name) + 1];
	strcpy_s(name, strlen(copy.name) + 1, copy.name);
}

Laptop::Laptop(const char* name, GraficsCard& gc, CPU& c, RAM& r, HDD& h):
	gc(gc), c(c), r(r), h(h), price(gc.GetPrice() + c.GetPrice() + r.GetPrice() + h.GetPrice() + 2000) {
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

Laptop::~Laptop() {
	delete[] name;
}

void Laptop::Input() {
	char buff[20];
	cout << "Enter name -> ";
	cin.getline(buff, 20);
	this->name = new char[strlen(buff) + 1];
	strcpy_s(this->name, strlen(buff) + 1, buff);

	cout << "Enter Grafics card: ";
	gc.Input();

	cout << "Enter CPU: ";
	c.Input();

	cout << "Enter RAM: ";
	r.Input();

	cout << "Enter HDD: ";
	h.Input();
}

void Laptop::Print() {
	cout << "Name: " << name << endl;
	cout << "Grafics card:" << endl;
	gc.Print();
	cout << "CPU: " << endl;
	c.Print();
	cout << "RAM: " << endl;
	r.Print();
	cout << "HDD: " << endl;
	h.Print();
	cout << "Laptop price: " << price << endl;
}

// Getters
const char* Laptop::getName() { return name; }
HDD Laptop::getHDD() { return h; }
GraficsCard Laptop::getGraficsCard() { return gc; }
CPU Laptop::getCPU() { return c; }
RAM Laptop::getRAM() { return r; }
double Laptop::getPrice() { return price; }

// Setters
void Laptop::setName(char* name) {
	if (name != nullptr) delete[] name;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}
void Laptop::setHDD(HDD h) { 
	this->h.SetName(h.GetName()); 
	this->h.SetPrice(h.GetPrice());
}
void Laptop::setGraficsCard(GraficsCard gc) { 
	this->gc.SetName(h.GetName());
	this->gc.SetPrice(h.GetPrice());
}
void Laptop::setCPU(CPU c) { this->c = c; }
void Laptop::setRAM(RAM r) { this->r = r; }