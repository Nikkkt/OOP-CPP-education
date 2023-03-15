#include <iostream>
#include <math.h>
#include "Triangle.h"

Triangle::Triangle(): SecondSide(0), ThirdSide(0) {}

Triangle::Triangle(double FirstSide, double SecondSide, double ThirdSide) : Figure(FirstSide), SecondSide(SecondSide), ThirdSide(ThirdSide) {}

double Triangle::GetFirstSide() { return Figure::GetSideLength(); }

double Triangle::GetSecondSide() { return SecondSide; }

double Triangle::GetThirdSide() { return ThirdSide; }

void Triangle::SetFirstSide(double FirstSide) { Figure::SetSideLength(FirstSide); }

void Triangle::SetSecondSide(double SecondSide) { this->SecondSide = SecondSide; }

void Triangle::SetThirdSide(double ThirdSide) { this->ThirdSide = ThirdSide; }

bool Triangle::isExist() {
	if (std::max(SideLength, std::max(SecondSide, ThirdSide)) == SideLength) if (SideLength < SecondSide + ThirdSide) return true;
	if (std::max(SideLength, std::max(SecondSide, ThirdSide)) == SecondSide) if (SecondSide < SideLength + ThirdSide) return true;
	if (std::max(SideLength, std::max(SecondSide, ThirdSide)) == ThirdSide) if (ThirdSide < SecondSide + SideLength) return true;
	return false;
}

double Triangle::Area() {
	double p = Perimeter() / 2;
	if (isExist()) return sqrt(p * (p - SideLength) * (p - SecondSide) * (p - ThirdSide));
	return -1;
}

double Triangle::Perimeter() { 
	if (isExist()) return SideLength + SecondSide + ThirdSide;
	return -1;
}