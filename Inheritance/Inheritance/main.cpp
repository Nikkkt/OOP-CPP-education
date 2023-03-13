#include <iostream>
#include "StepStudent.h"
#include "Bike.h"
#include "Car.h"
#include "Carriage.h"

int main() {
	StepStudent ss(5);
	ss.Show();
	std::cout << std::endl << std::endl;

	// speed - m/s ; weight - kg ; price - $
	Bike bike(5, 50, 1.25);
	bike.TimeAndPrice(100);
	bike.ShowWeight();

	Car car(20, 500, 7.5);
	car.TimeAndPrice(1000);
	car.ShowWeight();

	Carriage carriage(10, 250, 3.75);
	carriage.TimeAndPrice(750);
	carriage.ShowWeight();
}