#include "RAM.h"

RAM::RAM() : firm(""), GB(0) {}

RAM::RAM(std::string firm, int GB) : firm(firm), GB(GB) {}

void RAM::Show() { std::cout << "Firm: " << firm << std::endl << "GB: " << GB << std::endl; }