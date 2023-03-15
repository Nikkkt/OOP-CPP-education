#pragma once
#include "Figure.h"

class Elipse : protected Figure {
protected:
	double SecondDiameter;

public:
	Elipse();
	Elipse(double FirstDiameter, double SecondDiameter);

	double GetFirstDiameter();
	double GetSecondDiameter();

	void SetFirstDiameter(double FirstDiameter);
	void SetSecondDiameter(double SecondDiameter);

	double Area();
	double Perimeter();
};