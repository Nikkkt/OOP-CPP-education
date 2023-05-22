#include <iostream>
#include <algorithm>
#include <vector>

bool cmp(std::string str1, std::string str2) { return str1.length() < str2.length(); }

int main() {
	std::vector<std::string> vect = { "Hello", "Dobry wieczor", "Hi", "Buna", "Guten Tag" };
	for (auto el : vect) std::cout << el << std::endl;
	std::cout << std::endl;
	std::sort(vect.begin(), vect.end(), cmp);
	for (auto el : vect) std::cout << el << std::endl;
}