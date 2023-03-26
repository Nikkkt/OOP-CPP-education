#pragma once
#include <iostream>

class Equation {
protected:
    float a;
    float b;

public:
    Equation();
    Equation(float a, float b);

    virtual void ShowAnswer() = 0;
};

class LinearEquation : public Equation {
public:
    LinearEquation();
    LinearEquation(float k, float b);

    void ShowAnswer();
};

class QuadraticEquation : public Equation {
private:
    float c;

public:
    QuadraticEquation();
    QuadraticEquation(float a, float b, float c);

    void ShowAnswer();
};

Equation::Equation() : a(0), b(0) {}

Equation::Equation(float a, float b) : a(a), b(b) {}

LinearEquation::LinearEquation() : Equation() {}

LinearEquation::LinearEquation(float k, float b) : Equation(k, b) {}

void LinearEquation::ShowAnswer() { 
    if (a == 0 && b == 0) std::cout << "Root is any number" << std::endl;
    else if (a == 0 && b != 0) std::cout << "No roots" << std::endl;
    else std::cout << "Root of the equation: " << -b / a << std::endl; 
}

QuadraticEquation::QuadraticEquation() : c(0), Equation() {}

QuadraticEquation::QuadraticEquation(float a, float b, float c) : Equation(a, b), c(c) {}

void QuadraticEquation::ShowAnswer() {
    if (a == 0) { std::cout << "It is not a quadratic equation!" << std::endl; return; }
    if (std::pow(b, 2) - 4 * a * c < 0) std::cout << "No real solutions" << std::endl;
    else if (std::pow(b, 2) - 4 * a * c == 0) std::cout << "Root of the equation: " << -b / (2 * a) << std::endl;
    else {
        std::cout << "First root of the equation: " << (-b + std::sqrt(std::pow(b, 2) - 4 * a * c)) / (2 * a) << std::endl;
        std::cout << "Second root of the equation: " << (-b - std::sqrt(std::pow(b, 2) - 4 * a * c)) / (2 * a) << std::endl;
    }
}