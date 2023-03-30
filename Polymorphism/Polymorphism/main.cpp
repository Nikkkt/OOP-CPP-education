#include <iostream>
#include "first.h"
#include "second.h"
#include "third.h"

int main() {
    Employer* emp[3] = { new President("Nikita"), new Manager("Danya"), new Worker("Maksym") };
    for (int i = 0; i < 3; i++) emp[i]->Show();
    std::cout << std::endl;

    LinearEquation linear(2, 6);
    linear.ShowAnswer();

    QuadraticEquation quadratic(1, 5, 4);
    quadratic.ShowAnswer();

    Equation* eq[2] = { new LinearEquation(4, 8), new QuadraticEquation(1, -3, 2) };
    for (int i = 0; i < 2; i++) eq[i]->ShowAnswer();

    std::cout << std::endl;

    IAnimal* ref[4] = { new Cat("Cat", 3, "white"), new Elephant("Elephant", 400, "Grey"), new Penguin("Penguin", 15, "Black"), new Duck("Duck", 10, "Grey") };
    for (int i = 0; i < 4; i++) {
        ref[i]->Eat();
        ref[i]->Move();
    }

    ref[0] = new Parrot("Ara", 2, "Green");
    ref[0]->Eat();
    ref[0]->Move();

    ISwim* p[2] = { new Penguin("Penguin", 12, "Black"), new Duck("Duck", 10, "Grey") };
    for (int i = 0; i < 2; i++) p[i]->Swim();

    IBird* f[2] = { new Parrot("Ara", 3, "Green"), new Duck("Duck", 10, "Grey") };
    for (int i = 0; i < 2; i++) f[i]->Fly();
}