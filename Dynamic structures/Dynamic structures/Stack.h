#pragma once
class Stack {
private:
	char* st;
	int top;
	int size = 10;

public:
	Stack();
	Stack(int size);
	~Stack();

	void Push(char c);
	char Pop();
	void Clear();

	bool IsEmpty();
	bool IsFull();

	int GetCount();
};