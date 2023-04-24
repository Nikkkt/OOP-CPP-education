#include "includes.hpp"
#include <vector>

int main() {
	std::vector<int> vec = {1, 2, 3};
	std::vector<int> vec2(vec);
	std::cout << vec2[0];
}