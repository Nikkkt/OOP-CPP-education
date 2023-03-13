#include "Laptop.h"

Laptop::Laptop() {
	CPU cp("", 0.0);
	this->cp = cp;

	GPU gp("", 0);
	this->gp = gp;

	RAM ram("", 0);
	this->ram = ram;

	Mouse* mouse = new Mouse("", 0.0);
	this->mouse = mouse;

	Printer* printer = new Printer("", 0);
	this->printer = printer;

	Webcam* webcam = new Webcam("", "");
	this->webcam = webcam;
}

Laptop::Laptop(std::string firmCPU, float GHz, std::string firmGPU, int GBGPU, std::string firmRAM, int GBRAM, Mouse* mouse, Printer* printer, Webcam* webcam):
	cp(firmCPU, GHz), gp(firmGPU, GBGPU), ram(firmRAM, GBRAM), mouse(mouse), printer(printer), webcam(webcam) {}

void Laptop::Show() {
	std::cout << "CPU: " << std::endl;
	cp.Show();
	std::cout << "GPU: " << std::endl;
	gp.Show();
	std::cout << "RAM: " << std::endl;
	ram.Show();
	std::cout << "Mouse: " << std::endl;
	mouse->Show();
	std::cout << "Printer: " << std::endl;
	printer->Show();
	std::cout << "Webcam: " << std::endl;
	webcam->Show();
}