#pragma once
#include "Figure.h"

class Quadrangle : protected Figure {
protected:
	double SecondSide;
	double ThirdSide;
	double FourthSide;

public:
	Quadrangle();
	Quadrangle(double FirstSide, double SecondSide, double ThirdSide, double FourthSide);

	double GetFirstSide();
	double GetSecondSide();
	double GetThirdSide();
	double GetFourthSide();

	void SetFirstSide(double FirstSide);
	void SetSecondSide(double SecondSide);
	void SetThirdSide(double ThirdSide);
	void SetFourthSide(double FourthSide);

	bool isExist();
	double Area();
	double Perimeter();
};