#include <iostream>
#include <fstream>
#include <string>
#include "Fraction.h"

int main() {
	// 1
	std::fstream First("First.txt");
	std::ofstream newFirst("NewFirst.txt");
	if (!First || !newFirst) std::cout << "Something went wrong" << std::endl;
	while (First) {
		std::string tmp;
		First >> tmp;
		if (tmp.size() >= 8) { 
			if (tmp.find('.')) tmp.erase(std::remove(tmp.begin(), tmp.end(), '.'), tmp.end());
			if (tmp.find(',')) tmp.erase(std::remove(tmp.begin(), tmp.end(), ','), tmp.end());
			if (tmp.find(':')) tmp.erase(std::remove(tmp.begin(), tmp.end(), ':'), tmp.end());
			if (tmp.find('-')) tmp.erase(std::remove(tmp.begin(), tmp.end(), '-'), tmp.end());
			newFirst << tmp << std::endl; 
		}
	}
	First.close();
	newFirst.close();

	// 2
	std::fstream Second("Second.txt");
	std::ofstream newSecond("NewSecond.txt");
	if (!Second || !newSecond) std::cout << "Something went wrong" << std::endl;
	while (Second) {
		std::string tmp;
		std::getline(Second, tmp);
		newSecond << tmp << std::endl;
	}
	Second.close();
	newSecond.close();

	// 3
	Fraction f1[4] = { Fraction(1, 3), Fraction(3, 7), Fraction(4, 9), Fraction(6, 11) };
	Fraction f2[4];
	std::ofstream Third1("Third.dat", std::ios::binary);
	Third1.write((char*)f1, 4 * sizeof(Fraction));
	Third1.close();
	std::ifstream Third2("Third.dat", std::ios::binary);
	Third2.read((char*)f2, 4 * sizeof(Fraction));
	for (int i = 0; i < 4; i++) std::cout << f2[i] << std::endl;
	Third2.close();

	// 4
	Fraction f3[4] = { Fraction(1, 5), Fraction(5, 7), Fraction(4, 11), Fraction(10, 13) };
	Fraction f4;
	std::ofstream Fourth1("Fourth.dat", std::ios::binary);
	Fourth1.write((char*)f3, 4 * sizeof(Fraction));
	Fourth1.close();
	std::ifstream Fourth2("Fourth.dat", std::ios::binary);
	Fourth2.seekg(2 * sizeof(Fraction));
	Fourth2.read((char*)&f4, sizeof(Fraction));
	std::cout << f4 << std::endl;
	Fourth2.close();
}