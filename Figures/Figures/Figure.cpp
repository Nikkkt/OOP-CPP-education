#include <iostream>
#include <math.h>
#include "Figure.h"

Figure::Figure(): SideLength(0) {}

Figure::Figure(double SideLength): SideLength(SideLength) {}

double Figure::GetSideLength() { return SideLength; }

void Figure::SetSideLength(double SideLength) { this->SideLength = SideLength; }

double Figure::Area(int NumberOfSides) { return (SideLength / (double)(2 * tan(acos(-1.0) / (double)NumberOfSides))) * (SideLength * (double)NumberOfSides) / 2.0; }

double Figure::Perimeter(int NumberOfSides) { return SideLength * (double)NumberOfSides; }