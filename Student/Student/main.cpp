#include <iostream>
#include "Student.h"

int main() {
	srand(time(NULL));
	const char* name = "Nikita";
	int length = 10;
	int* rates = new int[length];
	for (int i = 0; i < length; i++) rates[i] = rand() % 5 + 7;

	Student s1(name, rates, length);
	s1.Print();

	Student s2 = s1;
	s2.Print();
	s2.setName("Vladislav");

	s1 = s2;
	s1.Print();
}