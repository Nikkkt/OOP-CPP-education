#include "List.h"
#include <iostream>

List::List() {
	head = tail = nullptr;
	count = 0;
}

List::~List() { DelAll(); }

int List::GetCount() { return count; }

void List::Add(char data) {
	node* temp = new node;

	temp->data = data;
	temp->next = nullptr;

	if (head != nullptr) {
		tail->next = temp;
		tail = temp;
	}
	else head = tail = temp;
	count++;
}

void List::AddByIndex(char data, int index) {
	if (index > count || index < 1) return;

	if (index == 1) {
		node* temp = head;
		head = new node;

		head->data = data;
		head->next = temp;
	}
	else if (index == count) {
		node* temp = tail;
		tail = new node;

		tail->data = data;
		tail->next = nullptr;

		temp->next = tail;
	}
	else {
		node* temp = head;
		for (int i = 1; i < index - 1; i++) temp = temp->next;

		node* prev = temp;
		node* next = temp->next;
		node* cur = new node;

		prev->next = cur;
		cur->data = data;
		cur->next = next;
	}
	count++;
}

void List::Del() {
	node* temp = head;
	head = head->next;
	delete temp;
}

void List::DelByIndex(int index) {
	if (index > count || index < 1) return;

	if (index == 1) {
		node* temp = head;
		head = head->next;
		delete temp;
	}
	else if (index == count) {
		node* temp = head;
		for (int i = 1; i < count - 1; i++) temp = temp->next;
		tail = temp;
		delete tail->next;
		tail->next = nullptr;
	}
	else {
		node* temp = head;
		for (int i = 1; i < count - 1; i++) temp = temp->next;

		node* prev = temp;
		node* cur = temp->next;
		node* next = cur->next;

		prev->next = next;
		delete cur;
	}
	count--;
}

void List::DelAll() { while (head != 0) Del(); }

void List::Print() {
	for (node* temp = head; temp != nullptr; temp = temp->next) std::cout << temp->data << " ";
	std::cout << std::endl << std::endl;
}

int List::Search(char data) {
	node* temp = head;
	for (int i = 1; temp != nullptr; temp = temp->next, i++) if (temp->data == data) return i;
	return 0;
}