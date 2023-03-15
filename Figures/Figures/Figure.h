#pragma once

class Figure {
protected:
	double SideLength;

public:
	Figure();
	Figure(double SideLength);

	double GetSideLength();
	void SetSideLength(double SideLength);

	double Area(int NumberOfSides);
	double Perimeter(int NumberOfSides);
};