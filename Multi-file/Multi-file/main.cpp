#include <iostream>
#include "HDD.h"
#include "GraficsCard.h"
#include "CPU.h"
#include "RAM.h"
#include "Laptop.h"
using namespace std;

int main() {
	HDD obj1("Asus", 256, 2500);
	GraficsCard obj2("Nvidia GTX 1660", 6, 11000);
	CPU obj3("Intel core i7", 3.6, 15000);
	RAM obj4("Fury", 16, 2600);
	Laptop lp("Dell", obj2, obj3, obj4, obj1);
	lp.Print();
}