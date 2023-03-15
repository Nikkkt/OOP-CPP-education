#pragma once
#include "Elipse.h"
#include "Quadrangle.h"

class CircleInscribedInSquare : protected Elipse, protected Quadrangle {
public:
	CircleInscribedInSquare();
	CircleInscribedInSquare(double value);

	double CircleArea();
	double CirclePerimeter();

	double SquareArea();
	double SquarePerimeter();

	double AreaOutsideCircle();
};