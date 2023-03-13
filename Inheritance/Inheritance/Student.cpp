#include "Student.h"

Student::Student() {
	name = "Nikita";
	age = 17;
}

Student::Student(std::string name, unsigned int age) {
	this->name = name;
	this->age = age;
}
