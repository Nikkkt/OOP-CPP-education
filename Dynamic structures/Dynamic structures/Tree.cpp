#include <iostream>
using namespace std;

#include "Tree.h"

Tree::Tree() : Root(nullptr), Size(0U) {}

Tree::~Tree() { while (Root != nullptr) Remove(Root); }

Elem* Tree::GetRoot() const { return Root; }

void Tree::Insert(Elem* newNode){
    newNode->Left = nullptr;
    newNode->Right = nullptr;

    Elem* el = Root;
    Elem* temp = nullptr;

    while (el != nullptr) {
        temp = el;

        if (strcmp(newNode->fullName, el->fullName) < 0) el = el->Left;
        else el = el->Right;
    }

    newNode->Parent = temp;

    if (temp == nullptr) Root = newNode;
    else if (strcmp(newNode->fullName, temp->fullName) < 0) temp->Left = newNode;
    else temp->Right = newNode;

    Size++;
}

Elem* Tree::Max(Elem* el) const {
    if (el != nullptr) while (el->Right != nullptr) el = el->Right;
    return el;
}

Elem* Tree::Min(Elem* el) const {
    if (el != nullptr) while (el->Left != nullptr) el = el->Left;
    return el;
}

Elem* Tree::Next(const Elem* el) const {
    Elem* next = nullptr;

    if (el != nullptr) {
        if (el->Right != nullptr) next = Min(el->Right);
        else {
            next = el->Parent;
            while (next != nullptr && el == next->Right) {
                el = next;
                next = next->Parent;
            }
        }
    }
    return next;
}

Elem* Tree::Previous(const Elem* el) const {
    Elem* previous = nullptr;

    if (el != nullptr) {
        if (el->Left != nullptr) previous = Max(el->Left);
        else {
            previous = el->Parent;
            while (previous != nullptr && el == previous->Left) {
                el = previous;
                previous = previous->Parent;
            }
        }
    }
    return previous;
}

void Tree::Print(const Elem* el) const {
    if (el != nullptr) {
        Print(el->Left);
        cout << el->fullName << '\t' << el->average << endl;
        Print(el->Right);
    }
}

void Tree::Remove(Elem* removeNode) {
    if (removeNode != nullptr) {
        Elem* el = nullptr;
        Elem* temp = nullptr;

        if (removeNode->Left == nullptr || removeNode->Right == nullptr) temp = removeNode;
        else temp = Next(removeNode);

        if (temp->Left != nullptr) el = temp->Left;
        else el = temp->Right;

        if (el != nullptr) el->Parent = temp->Parent;

        if (temp->Parent == nullptr) Root = el;
        else if (temp == temp->Parent->Left) temp->Parent->Left = el;
        else temp->Parent->Right = el;

        if (temp != removeNode) {
            strcpy_s(removeNode->fullName, 15U, temp->fullName);
            removeNode->average = temp->average;
        }

        delete temp;
        Size--;
    }
}

Elem* Tree::Search(Elem* el, const char* key) const {
    while (el != nullptr && strcmp(key, el->fullName) != 0) {
        if (strcmp(key, el->fullName) < 0) el = el->Left;
        else el = el->Right;
    }
    return el;
}