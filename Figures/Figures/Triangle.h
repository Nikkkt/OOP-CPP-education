#pragma once
#include "Figure.h"

class Triangle : protected Figure {
private:
	double SecondSide;
	double ThirdSide;

public:
	Triangle();
	Triangle(double FirstSide, double SecondSide, double ThirdSide);

	double GetFirstSide();
	double GetSecondSide();
	double GetThirdSide();

	void SetFirstSide(double FirstSide);
	void SetSecondSide(double SecondSide);
	void SetThirdSide(double ThirdSide);

	bool isExist();
	double Area();
	double Perimeter();
};