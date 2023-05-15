#include <iostream>
#include "Animals.hpp"

int main() {
    Animal* animals[3] = { new Frog(), new Dog(), new Cat() };
    for (int i = 0; i < 3; i++) animals[i]->Speak();

    Cat* cat = dynamic_cast<Cat*>(animals[2]);
    cat->Scratch(false);
    cat->Scratch(true);
    cat->Purr();

    for (int i = 0; i < 3; i++) delete animals[i];
}