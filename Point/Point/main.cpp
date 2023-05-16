#include <iostream>
#include <vector>
#include <list>
#include <set>
#include "Point.h"

int main() {
	srand(time(NULL));

	//Point p1(1.5, 2.3), p2(2.6, 3.5), p3(3.4, 4.8);
	//Point p4 = p1 + p2;
	//std::cout << p4 << std::endl; // (4.10, 5.80)
	//Point p5 = p4 - p3;
	//p5.Print(); // (0.70, 1.00)

	//// vector
	//std::vector<Point> pointVect;
	//for (int i = 0; i < 5; i++) {
	//	Point tmp;
	//	std::cin >> tmp;
	//	pointVect.push_back(tmp);
	//}
	//for (int i = 0; i < 5; i++) std::cout << pointVect[i] << std::endl;

	//// list
	//std::list<Point> pointList;
	//for (int i = 0; i < 5; i++) {
	//	Point tmp;
	//	std::cin >> tmp;
	//	pointList.push_back(tmp);
	//}
	//for (auto i = pointList.begin(); i != pointList.end(); i++) std::cout << *i << std::endl;
	//for (Point point : pointList) std::cout << point << std::endl;

	// set
	std::set<std::set<std::set<std::set<Point>>>> pointSet;
	for (int i = 0; i < 5; i++) {
		std::set<std::set<std::set<Point>>> tmp1;
		for (int j = 0; j < 5; j++) {
			std::set<std::set<Point>> tmp2;
			for (int k = 0; k < 5; k++) {
				std::set<Point> tmp3;
				for (int n = 0; n < 5; n++) tmp3.insert(Point(rand() % 100, rand() % 100));
				tmp2.insert(tmp3);
			}
			tmp1.insert(tmp2);
		}
		pointSet.insert(tmp1);
	}

	std::set<std::set<std::set<std::set<Point>>>>::const_iterator iterator;
	iterator = pointSet.begin();
	while (iterator != pointSet.end()) {
		std::set<std::set<std::set<Point>>>::const_iterator iterator2 = (*iterator).begin();
		while (iterator2 != (*iterator).end()) {
			std::set<std::set<Point>>::const_iterator iterator3 = (*iterator2).begin();
			while (iterator3 != (*iterator2).end()) {
				std::set<Point>::const_iterator iterator4 = (*iterator3).begin();
				while (iterator4 != (*iterator3).end()) {
					std::cout << *iterator4 << ", ";
					iterator4++;
				}
				std::cout << std::endl;
				iterator3++;
			}
			std::cout << std::endl;
			iterator2++;
		}
		std::cout << std::endl;
		iterator++;
	}

	Point searchPoint;
	std::cout << "Search for Point: " << std::endl;
	std::cin >> searchPoint;

	bool found = false;

	iterator = pointSet.begin();
	while (iterator != pointSet.end()) {
		std::set<std::set<std::set<Point>>>::const_iterator iterator2 = (*iterator).begin();
		while (iterator2 != (*iterator).end()) {
			std::set<std::set<Point>>::const_iterator iterator3 = (*iterator2).begin();
			while (iterator3 != (*iterator2).end()) {
				std::set<Point>::const_iterator iterator4 = (*iterator3).begin();
				iterator4 = (*iterator3).find(searchPoint);
				if (iterator4 != (*iterator3).end()) found = true;
				iterator3++;
			}
			iterator2++;
		}
		iterator++;
	}
	if (found) std::cout << "found" << std::endl;
	else std::cout << "Not found" << std::endl;
}