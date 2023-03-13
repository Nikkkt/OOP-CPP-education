#pragma once
#include <iostream>

class Student {
protected:
	std::string name;
	unsigned int age;

public:
	Student();
	Student(std::string name, unsigned int age);
};