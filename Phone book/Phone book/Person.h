#pragma once
class Person {
private:
    char* fullName;
    char* homePhone;
    char* workPhone;
    char* mobilePhone;
    char* additionalInfo;

public:
    Person();
    Person(const char* fullName, const char* homePhone, const char* workPhone, const char* mobilePhone, const char* additionalInfo);
    Person(const Person& person);
    ~Person();

    void Print();
    void Init();
    char* GetName();

    void operator = (const Person& person);
};