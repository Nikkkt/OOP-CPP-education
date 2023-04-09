#pragma once
#include <iostream>

class Fraction {
private:
	int num;
	int den;

public:
	Fraction();
	Fraction(int num, int den);

    void Reduction();

    Fraction operator+(Fraction b);
    Fraction operator-(Fraction b);

    Fraction operator+(float b);
    Fraction operator-(float b);

    Fraction operator*(Fraction b);
    Fraction operator*(float b);

    Fraction& operator++();
    Fraction& operator--();

    Fraction operator++(int);
    Fraction operator--(int);

    void SetNumerator(int num);
    void SetDenominator(int den);

    float GetNumerator() const;
    float GetDenominator() const;
};

std::ostream& operator << (std::ostream& o, const Fraction& p);