#include "StepStudent.h"

StepStudent::StepStudent() { technologies = 0; }

StepStudent::StepStudent(unsigned int technologies) { this->technologies = technologies; }

void StepStudent::Show() { std::cout << "Name: " << name << std::endl << "Age: " << age << std::endl << "Technologies: " << technologies << std::endl; }