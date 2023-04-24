#include <iostream>
#include <vector>
#include "Point.h"

int main() {
	Point p1(1.5, 2.3), p2(2.6, 3.5), p3(3.4, 4.8);
	Point p4 = p1 + p2;
	std::cout << p4 << std::endl; // (4.10, 5.80)
	Point p5 = p4 - p3;
	p5.Print(); // (0.70, 1.00)

	std::vector<Point> pointVect;
	for (int i = 0; i < 5; i++) {
		Point tmp;
		std::cin >> tmp;
		pointVect.push_back(tmp);
	}
	for (int i = 0; i < 5; i++) std::cout << pointVect[i] << std::endl;
}