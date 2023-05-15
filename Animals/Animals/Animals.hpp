#pragma once

class Animal {
public:
    virtual void Speak() = 0;
};

class Frog : public Animal {
public:
    void Speak() { std::cout << "Kwa" << std::endl; }
};

class Dog : public Animal {
public:
    void Speak() { std::cout << "Gaw" << std::endl; }
};

class Cat : public Animal {
public:
    void Speak() { std::cout << "Meow" << std::endl; }
    void Scratch(bool isHomeworkDone) {
        if (isHomeworkDone) std::cout << "The cat doesn't scratch" << std::endl;
        else std::cout << "The cat scratches" << std::endl;
    }
    void Purr() { std::cout << "The cat purrs" << std::endl; }
};