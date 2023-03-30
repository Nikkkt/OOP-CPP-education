#pragma once
#include <iostream>

bool isALuckyNumber(int number) {
	if (number < 100000) throw "The number is too small";
	else if (number > 999999) throw std::exception("The number is to big");
	else return (number / 100000 + number / 10000 % 10 + number / 1000 % 10) == (number / 100 % 10 + number / 10 % 10 + number % 10);
}