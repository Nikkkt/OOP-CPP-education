#pragma once
#include <iostream>

class Fraction {
private:
    int m_numerator;
    int m_denominator;

public:
    Fraction() : m_numerator(0), m_denominator(1) {}
    Fraction(int numerator, int denominator) : m_numerator(numerator), m_denominator(denominator) {}

    friend std::ostream& operator << (std::ostream& out, const Fraction& f1) { out << f1.m_numerator << "/" << f1.m_denominator; return out; }
};