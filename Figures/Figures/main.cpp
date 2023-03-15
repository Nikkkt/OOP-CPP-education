#include <iostream>
#include "Figure.h"
#include "Triangle.h"
#include "Quadrangle.h"
#include "Elipse.h"
#include "CircleInscribedInSquare.h"

int main() {
	// Class Figure for regular polygons
	Figure f1(2);
	std::cout << f1.Area(4) << std::endl; // 4
	std::cout << f1.Perimeter(4) << std::endl << std::endl; // 8


	// Class Triangle for arbitrary triangles
	Triangle t1(13, 14, 15);
	std::cout << t1.Area() << std::endl; // 84
	std::cout << t1.Perimeter() << std::endl << std::endl; // 42

	Triangle t2(5, 7, 13);
	std::cout << std::boolalpha << t2.isExist() << std::endl; // false
	std::cout << t2.Area() << std::endl; // -1
	std::cout << t2.Perimeter() << std::endl << std::endl; // -1


	// Class Quadrangle for arbitrary quadrangles
	Quadrangle q1(2, 3, 4, 5);
	std::cout << q1.Area() << std::endl; // 10.9545
	std::cout << q1.Perimeter() << std::endl << std::endl; // 14

	Quadrangle q2(5, 5, 6, 6);
	std::cout << q2.Area() << std::endl; // 30
	std::cout << q2.Perimeter() << std::endl << std::endl; // 22

	Quadrangle q3(5, 7, 8, 20);
	std::cout << std::boolalpha << q3.isExist() << std::endl; // false
	std::cout << q3.Area() << std::endl; // -1
	std::cout << q3.Perimeter() << std::endl << std::endl; // -1


	// Class Elipse for arbitrary elipses
	Elipse e1(3, 5);
	std::cout << e1.Area() << std::endl; // 11.781
	std::cout << e1.Perimeter() << std::endl << std::endl; // 12.281

	Elipse e2(6, 6);
	std::cout << e2.Area() << std::endl; // 28.2743
	std::cout << e2.Perimeter() << std::endl << std::endl; // 18.8496


	// Class CircleInscribedInSquare for circles inscribed in squares
	CircleInscribedInSquare ciis(6);
	std::cout << ciis.AreaOutsideCircle() << std::endl; // 7.72567
	std::cout << ciis.CircleArea() << std::endl; // 28.2743
	std::cout << ciis.CirclePerimeter() << std::endl; // 18.8496
	std::cout << ciis.SquareArea() << std::endl; // 36
	std::cout << ciis.SquarePerimeter() << std::endl << std::endl; // 24
}