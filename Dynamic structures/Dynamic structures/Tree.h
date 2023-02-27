#pragma once
#include "Elem.h"

class Tree
{
    Elem* Root;
    unsigned int Size;

public:
    Tree();
    ~Tree();

    Elem* GetRoot() const;

    void Insert(Elem* el);

    Elem* Max(Elem* el) const;
    Elem* Min(Elem* el) const;

    Elem* Next(const Elem* el) const;
    Elem* Previous(const Elem* el) const;

    void Print(const Elem* el) const;
    void Remove(Elem* el);
    Elem* Search(Elem* el, const char* key) const;
};