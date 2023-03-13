#include "Mouse.h"

Mouse::Mouse() : firm(""), ReactionSpeed(0.0) {}

Mouse::Mouse(std::string firm, float ReactionSpeed) : firm(firm), ReactionSpeed(ReactionSpeed) {}

void Mouse::Show() { std::cout << "Firm: " << firm << std::endl << "Reaction speed (ms): " << ReactionSpeed << std::endl; }