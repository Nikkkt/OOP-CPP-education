#include <iostream>
#include <math.h>
#include "Quadrangle.h"

Quadrangle::Quadrangle() : SecondSide(0), ThirdSide(0), FourthSide(0) {}

Quadrangle::Quadrangle(double FirstSide, double SecondSide, double ThirdSide, double FourthSide) : Figure(FirstSide), SecondSide(SecondSide), ThirdSide(ThirdSide), FourthSide(FourthSide) {}

double Quadrangle::GetFirstSide() { return Figure::GetSideLength(); }

double Quadrangle::GetSecondSide() { return SecondSide; }

double Quadrangle::GetThirdSide() { return ThirdSide; }

double Quadrangle::GetFourthSide() { return FourthSide; }

void Quadrangle::SetFirstSide(double FirstSide) { Figure::SetSideLength(FirstSide); }

void Quadrangle::SetSecondSide(double SecondSide) { this->SecondSide = SecondSide; }

void Quadrangle::SetThirdSide(double ThirdSide) { this->ThirdSide = ThirdSide; }

void Quadrangle::SetFourthSide(double FourthSide) { this->FourthSide = FourthSide; }

bool Quadrangle::isExist() {
	if (std::max(std::max(SideLength, FourthSide), std::max(SecondSide, ThirdSide)) == SideLength) if (SideLength < SecondSide + ThirdSide + FourthSide) return true;
	if (std::max(std::max(SideLength, FourthSide), std::max(SecondSide, ThirdSide)) == SecondSide) if (SecondSide < SideLength + ThirdSide + FourthSide) return true;
	if (std::max(std::max(SideLength, FourthSide), std::max(SecondSide, ThirdSide)) == ThirdSide) if (ThirdSide < SecondSide + SideLength + FourthSide) return true;
	if (std::max(std::max(SideLength, FourthSide), std::max(SecondSide, ThirdSide)) == FourthSide) if (FourthSide < SecondSide + ThirdSide + SideLength) return true;
	return false;
}

double Quadrangle::Area() {
	double p = Perimeter() / 2;
	if (isExist()) return sqrt((p - SideLength) * (p - SecondSide) * (p - ThirdSide) * (p - FourthSide));
	return -1;
}

double Quadrangle::Perimeter() {
	if (isExist()) return SideLength + SecondSide + ThirdSide + FourthSide;
	return -1;
}