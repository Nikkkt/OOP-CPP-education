#pragma once
#include "Person.h"
#include <iostream>

class PhoneBook {
private:
	Person* persons;
	int length;

    PhoneBook(int length);

public:
    PhoneBook();
    PhoneBook(Person* persons, int length);
    PhoneBook(const PhoneBook& phoneBook);
    ~PhoneBook();

    void Print();
    void PrintNames();
    void AddPersonData();
    void AddPersonData(const Person& person);
    void DeletePerson(int index);
    void Search(char* name);

    Person* GetPersons() const;
    int GetSize() const;

    void SetPhoneBook(Person* persons, int length);

    PhoneBook& operator = (const PhoneBook& phoneBook);
    Person& operator [] (int index);
    friend std::ostream& operator << (std::ostream& o, const PhoneBook& pb);
};