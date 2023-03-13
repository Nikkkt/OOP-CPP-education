#include <iostream>
#include "CPU.h"
#include "GPU.h"
#include "RAM.h"
#include "Mouse.h"
#include "Printer.h"
#include "Webcam.h"
#include "Laptop.h"

int main() {
	Laptop lt1;
	lt1.Show();
	std::cout << std::endl;

	Mouse mouse("Hator", 0.3);
	Printer printer("LG", 10);
	Webcam webcam("Samsung", "1080p60");

	Laptop* lt2 = new Laptop("Intel", 3.2, "GeForce RTX 2080 Ti", 8, "Kingston", 16, &mouse, &printer, &webcam);
	lt2->Show();
	delete lt2;
	std::cout << std::endl;

	Laptop* lt3 = new Laptop("Intel core i7", 3.2, "GeForce RTX 3080 Ti", 16, "Kingston", 32, &mouse, &printer, &webcam);
	lt3->Show();
	delete lt3;
	std::cout << std::endl;
}