#pragma once
#include "Person.h"

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

    void operator = (const PhoneBook& phoneBook);
};