#include <iostream>
#include <limits>
#include "Fraction.h"

Fraction::Fraction(): num(1), den(1) {}
Fraction::Fraction(int num, int den) {
	if (den == 0) {
		this->num = std::numeric_limits<int>::max();
		this->den = 1;
	}
	else {
		this->num = num;
		this->den = den;
	}
}

void Fraction::Reduction() {
	for (int i = den; i >= 1; i--) {
		if (num % i == 0 && den % i == 0) {
			int num_res = num / i;
			int den_res = den / i;
			num = num_res;
			den = den_res;
		}
	}
}

Fraction Fraction::operator + (Fraction b) {
	int first = (num * b.den) + (den * b.num);
	int second = den * b.den;
	Fraction res(first, second);
	res.Reduction();
	return res;
}

Fraction Fraction::operator - (Fraction b) { 
	int first = (num * b.den) - (den * b.num);
	int second = den * b.den;
	Fraction res(first, second);
	res.Reduction();
	return res;
}

Fraction Fraction::operator + (float b) { 
	float first = (float)num + ((float)den * b);
	while (first - (int)first > 0) {
		first *= 10;
		den *= 10;
	}
	Fraction res(first, den);
	res.Reduction();
	return res;
}

Fraction Fraction::operator - (float b) { 
	float first = (float)num - ((float)den * b);
	while (first - (int)first > 0) {
		first *= 10;
		den *= 10;
	}
	Fraction res(first, den);
	res.Reduction();
	return res;
}

Fraction Fraction::operator * (Fraction b) { 
	Fraction res(num * b.num, den * b.den);
	res.Reduction();
	return res; 
}

Fraction Fraction::operator * (float b) { 
	float first = num * b;
	while (first - (int)first > 0) {
		first *= 10;
		den *= 10;
	}
	Fraction res(first, den);
	res.Reduction();
	return res;
}

Fraction& Fraction::operator ++ () {
	num += den;
	return *this;
}

Fraction& Fraction::operator -- () {
	num -= den;
	return *this;
}

Fraction Fraction::operator ++ (int) {
	Fraction tmp(num, den);
	num += den;
	return tmp;
}

Fraction Fraction::operator -- (int) {
	Fraction tmp(num, den);
	num -= den;
	return tmp;
}

float Fraction::GetNumerator() const { return num; }
float Fraction::GetDenominator() const { return den; }

void Fraction::SetNumerator(int num) { this->num = num; }
void Fraction::SetDenominator(int den) { this->den = den; }

std::ostream& operator << (std::ostream& o, const Fraction& p) {
	o << p.GetNumerator() << "/" << p.GetDenominator();
	return o;
}