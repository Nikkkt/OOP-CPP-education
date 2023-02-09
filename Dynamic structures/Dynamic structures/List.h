#pragma once
struct node {
	char data;
	node* next;
};

class List {
private:
	node* head;
	node* tail;
	int count;

public:
	List();
	~List();

	void Add(char data);
	void AddByIndex(char data, int index);

	void Del();
	void DelByIndex(int index);
	void DelAll();

	int Search(char data);

	void Print();
	int GetCount();
};