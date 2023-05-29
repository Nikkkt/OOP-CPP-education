#include <iostream>
#include <vector>
#include <algorithm>

class Compare {
public:
	bool operator() (std::string a, std::string b) { return a.length() < b.length(); }
};

class Add {
	int num;

public:
	Add(int num) : num(num) {}
	void operator() (int& elem) { elem += num; }
};

class Multiply {
	int num;

public:
	Multiply(int num) : num(num) {}
	void operator() (int& elem) { elem *= num; }
};

int main() {
	srand(time(0));

	// 1
	std::vector<std::string> vec1;
	for (int i = 0; i < 5; i++){
		std::string tmp = "";
		int randLenght = rand() % 10 + 2;
		for (int j = 0; j < randLenght; j++) tmp += (char)(rand() % 26 + 65);
		vec1.push_back(tmp);
	}
	for (int i = 0; i < vec1.size(); i++) std::cout << vec1[i] << std::endl;
	Compare Compare;
	std::sort(vec1.begin(), vec1.end(), Compare);
	std::cout << std::endl;
	for (int i = 0; i < vec1.size(); i++) std::cout << vec1[i] << std::endl;

	// 2
	std::vector<int> vec2;
	for (int i = 0; i < 10; i++) vec2.push_back(rand() % 89 + 10);
	for (auto& elem : vec2) std::cout << elem << " ";
	std::cout << std::endl;
	std::for_each(vec2.begin(), vec2.end(), Add(10));
	for (auto& elem : vec2) std::cout << elem << " ";
	std::cout << std::endl;

	// 3
	std::vector<int> vec3;
	for (int i = 0; i < 10; i++) vec3.push_back(rand() % 89 + 10);
	for (auto& elem : vec3) std::cout << elem << " ";
	std::cout << std::endl;
	std::for_each(vec3.begin(), vec3.end(), Multiply(3));
	for (auto& elem : vec3) std::cout << elem << " ";
	std::cout << std::endl;
}