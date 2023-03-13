#include "GPU.h"

GPU::GPU() : firm(""), GB(0) {}

GPU::GPU(std::string firm, int GB) : firm(firm), GB(GB) {}

void GPU::Show() { std::cout << "Firm: " << firm << std::endl << "GB: " << GB << std::endl; }