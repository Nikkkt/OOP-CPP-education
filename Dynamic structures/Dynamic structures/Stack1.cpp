#include "Stack.h"
#include <iostream>

Stack::Stack() {
	st = new char[size + 1];
	top = -1;
}

Stack::Stack(int size) {
	this->size = size;
	st = new char[this->size + 1];
	top = -1;
}

Stack::~Stack() { delete[] st; }

bool Stack::IsEmpty() { return top == -1; }
bool Stack::IsFull() { return top == size; }

void Stack::Clear() { top = -1; }
int Stack::GetCount() { return top; }
void Stack::Push(char c) { if (!IsFull()) st[++top] = c; }

char Stack::Pop() {
	if (!IsEmpty()) return st[top--];
	else return 0;
}