#pragma once
#include <iostream>
#include "CPU.h"
#include "GPU.h"
#include "RAM.h"
#include "Mouse.h"
#include "Printer.h"
#include "Webcam.h"

class Laptop {
private:
	CPU cp;
	GPU gp;
	RAM ram;
	Mouse* mouse;
	Printer* printer;
	Webcam* webcam;

public:
	Laptop();
	Laptop(std::string firmCPU, float GHz, std::string firmGPU, int GBGPU, std::string firmRAM, int GBRAM, Mouse* mouse, Printer* printer, Webcam* webcam);

	void Show();
};