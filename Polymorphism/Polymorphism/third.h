#pragma once
#include <iostream>
using namespace std;

class Animal {
protected:
    string name;
    int kg;

public:
    Animal() = default;
    Animal(string n, int k) {
        name = n;
        kg = k;
    }
    virtual void Print() = 0;
};

struct IAnimal {
    virtual void Eat() = 0;
    virtual void Move() = 0;
};

struct IBird { virtual void Fly() = 0; };

struct ISwim { virtual void Swim() = 0; };

class Cat : public Animal, public IAnimal {
private:
    string color;

public:
    Cat(string n, int k, string c) : Animal(n, k) { color = c; }

    void Print() {
        cout << "Name: " << name << endl;
        cout << "Kg: " << kg << endl;
        cout << "Color: " << color << endl;
    }

    void Eat() { cout << "Cat eats" << endl; }
    void Move() { cout << "Cat moves" << endl; }
};

class Elephant : public Animal, public IAnimal {
private:
    string color;

public:
    Elephant(string n, int k, string c) : Animal(n, k) { color = c; }

    void Print() {
        cout << "Name: " << name << endl;
        cout << "Kg: " << kg << endl;
        cout << "Color: " << color << endl;
    }

    void Eat() { cout << "Elephant eats" << endl; }
    void Move() { cout << "Elephant moves" << endl; }
};

class Penguin : public Animal, public IAnimal, public ISwim {
private:
    string color;

public:
    Penguin(string n, int k, string c) : Animal(n, k) { color = c; }

    void Print() {
        cout << "Name: " << name << endl;
        cout << "Kg: " << kg << endl;
        cout << "Color: " << color << endl;
    }

    void Eat() { cout << "Penguin eats" << endl; }
    void Move() { cout << "Penguin moves" << endl; }
    void Swim() { cout << "Penguin swims" << endl; }
};

class Parrot : public Animal, public IAnimal, public IBird {
private:
    string color;

public:
    Parrot(string n, int k, string c) : Animal(n, k) { color = c; }

    void Print() {
        cout << "Name: " << name << endl;
        cout << "Kg: " << kg << endl;
        cout << "Color: " << color << endl;
    }

    void Eat() { cout << "Parrot eats" << endl; }
    void Move() { cout << "Parrot moves" << endl; }
    void Fly() { cout << "Parrot flies" << endl; }
};

class Duck : public Animal, public IAnimal, public IBird, public ISwim {
private:
    string color;

public:
    Duck(string n, int k, string c) : Animal(n, k) { color = c; }

    void Print() {
        cout << "Name: " << name << endl;
        cout << "Kg: " << kg << endl;
        cout << "Color: " << color << endl;
    }

    void Eat() { cout << "Duck eats" << endl; }
    void Move() { cout << "Duck moves" << endl; }
    void Fly() { cout << "Duck flies" << endl; }
    void Swim() { cout << "Duck swims" << endl; }
};