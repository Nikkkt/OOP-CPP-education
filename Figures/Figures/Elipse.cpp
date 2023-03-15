#include <iostream>
#include <math.h>
#include "Elipse.h"

Elipse::Elipse(): SecondDiameter(0) {}

Elipse::Elipse(double FirstDiameter, double SecondDiameter): Figure(FirstDiameter), SecondDiameter(SecondDiameter) {}

double Elipse::GetFirstDiameter() { return Figure::GetSideLength(); }

double Elipse::GetSecondDiameter() { return SecondDiameter; }

void Elipse::SetFirstDiameter(double FirstDiameter) { Figure::SetSideLength(FirstDiameter); }

void Elipse::SetSecondDiameter(double SecondDiameter) { this->SecondDiameter = SecondDiameter; }

double Elipse::Area() { return (acos(-1.0) * SideLength * SecondDiameter) / 4; }

double Elipse::Perimeter() {
	if (SideLength < SecondDiameter) return 2 * ((acos(-1.0) * SideLength * SecondDiameter + (SecondDiameter - SideLength)) / (SecondDiameter + SideLength));
	return 2 * ((acos(-1.0) * SideLength * SecondDiameter + (SideLength - SecondDiameter)) / (SecondDiameter + SideLength));
}