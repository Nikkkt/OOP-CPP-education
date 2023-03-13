#include "CPU.h"

CPU::CPU(): firm(""), GHz(0.0) {}

CPU::CPU(std::string firm, float GHz): firm(firm), GHz(GHz) {}

void CPU::Show() { std::cout << "Firm: " << firm << std::endl << "GHz: " << GHz << std::endl; }