#include <iostream>
#include <math.h>
#include "CircleInscribedInSquare.h"

CircleInscribedInSquare::CircleInscribedInSquare() {}

CircleInscribedInSquare::CircleInscribedInSquare(double value) : Elipse(value, value), Quadrangle(value, value, value, value) {}

double CircleInscribedInSquare::CircleArea() { return acos(-1.0) * pow(SecondDiameter / 2, 2); }

double CircleInscribedInSquare::CirclePerimeter() { return 2 * acos(-1.0) * (SecondDiameter / 2); }

double CircleInscribedInSquare::SquareArea() { return pow(SecondSide, 2); }

double CircleInscribedInSquare::SquarePerimeter() { return 4 * SecondSide; }

double CircleInscribedInSquare::AreaOutsideCircle() { return SquareArea() - CircleArea(); }