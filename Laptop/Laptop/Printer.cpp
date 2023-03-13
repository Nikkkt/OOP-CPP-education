#include "Printer.h"

Printer::Printer() : firm(""), PrintSpeed(0) {}

Printer::Printer(std::string firm, int PrintSpeed) : firm(firm), PrintSpeed(PrintSpeed) {}

void Printer::Show() { std::cout << "Firm: " << firm << std::endl << "Print speed (s): " << PrintSpeed << std::endl; }