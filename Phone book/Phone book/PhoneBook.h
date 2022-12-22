#pragma once
#include "Person.h"

class PhoneBook {
private:
	Person* book;
	int size = 0;

public:
	PhoneBook();
	~PhoneBook();

	void Add();
	void Delete();
	void Search();
	void Show();
	void Run();
};