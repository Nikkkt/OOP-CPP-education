#include "Person.h"
#include <iostream>

Person::Person() {
    fullName = nullptr;
    homePhone = nullptr;
    workPhone = nullptr;
    mobilePhone = nullptr;
    additionalInfo = nullptr;
}

Person::Person(const char* fullName, const char* homePhone, const char* workPhone, const char* mobilePhone, const char* additionalInfo) {
    this->fullName = new char[strlen(fullName) + 1];
    strcpy_s(this->fullName, strlen(fullName) + 1, fullName);

    this->homePhone = new char[strlen(homePhone) + 1];
    strcpy_s(this->homePhone, strlen(homePhone) + 1, homePhone);

    this->workPhone = new char[strlen(workPhone) + 1];
    strcpy_s(this->workPhone, strlen(workPhone) + 1, workPhone);

    this->mobilePhone = new char[strlen(mobilePhone) + 1];
    strcpy_s(this->mobilePhone, strlen(mobilePhone) + 1, mobilePhone);

    this->additionalInfo = new char[strlen(additionalInfo) + 1];
    strcpy_s(this->additionalInfo, strlen(additionalInfo) + 1, additionalInfo);
}

Person::Person(const Person& person) {
    if (this->fullName != nullptr) delete[] this->fullName;
    if (this->homePhone != nullptr) delete[] this->homePhone;
    if (this->workPhone != nullptr) delete[] this->workPhone;
    if (this->mobilePhone != nullptr) delete[] this->mobilePhone;
    if (this->additionalInfo != nullptr) delete[] this->additionalInfo;

    this->fullName = new char[strlen(person.fullName) + 1];
    strcpy_s(this->fullName, strlen(person.fullName) + 1, person.fullName);

    this->homePhone = new char[strlen(person.homePhone) + 1];
    strcpy_s(this->homePhone, strlen(person.homePhone) + 1, person.homePhone);

    this->workPhone = new char[strlen(person.workPhone) + 1];
    strcpy_s(this->workPhone, strlen(person.workPhone) + 1, person.workPhone);

    this->mobilePhone = new char[strlen(person.mobilePhone) + 1];
    strcpy_s(this->mobilePhone, strlen(person.mobilePhone) + 1, person.mobilePhone);

    this->additionalInfo = new char[strlen(person.additionalInfo) + 1];
    strcpy_s(this->additionalInfo, strlen(person.additionalInfo) + 1, person.additionalInfo);
}

Person::~Person() {
    delete[] fullName;
    delete[] homePhone;
    delete[] workPhone;
    delete[] mobilePhone;
    delete[] additionalInfo;
}

void Person::Print() {
    if (fullName != nullptr) std::cout << fullName << "`s phone numbers:" << std::endl;
    else std::cout << "None phone numbers:" << std::endl;

    if (homePhone != nullptr) std::cout << "- Home phone: " << homePhone << std::endl;
    else std::cout << "- Home phone: None" << std::endl;

    if (workPhone != nullptr) std::cout << "- Work phone: " << workPhone << std::endl;
    else std::cout << "- Work phone: None" << std::endl;

    if (mobilePhone != nullptr) std::cout << "- Mobile phone: " << mobilePhone << std::endl;
    else std::cout << "- Mobile phone: None" << std::endl;

    if (additionalInfo != nullptr) std::cout << "Additional info: " << additionalInfo << std::endl;
    else std::cout << "Additional info: None" << std::endl;
}

void Person::Init() {
    if (this->fullName != nullptr) delete[] this->fullName;
    if (this->homePhone != nullptr) delete[] this->homePhone;
    if (this->workPhone != nullptr) delete[] this->workPhone;
    if (this->mobilePhone != nullptr) delete[] this->mobilePhone;
    if (this->additionalInfo != nullptr) delete[] this->additionalInfo;
    char buf[200];

    std::cin.ignore();

    std::cout << "Enter full name: ";
    std::cin.getline(buf, 200);
    this->fullName = new char[strlen(buf) + 1];
    strcpy_s(this->fullName, strlen(buf) + 1, buf);

    system("cls");

    std::cout << "Enter home phone: ";
    std::cin.getline(buf, 200);
    this->homePhone = new char[strlen(buf) + 1];
    strcpy_s(this->homePhone, strlen(buf) + 1, buf);

    system("cls");

    std::cout << "Enter work phone: ";
    std::cin.getline(buf, 200);
    this->workPhone = new char[strlen(buf) + 1];
    strcpy_s(this->workPhone, strlen(buf) + 1, buf);

    system("cls");

    std::cout << "Enter mobile phone: ";
    std::cin.getline(buf, 200);
    this->mobilePhone = new char[strlen(buf) + 1];
    strcpy_s(this->mobilePhone, strlen(buf) + 1, buf);

    system("cls");

    std::cout << "Enter additional info: ";
    std::cin.getline(buf, 200);
    this->additionalInfo = new char[strlen(buf) + 1];
    strcpy_s(this->additionalInfo, strlen(buf) + 1, buf);

    system("cls");
}

char* Person::GetName() { return fullName; }

void Person::operator = (const Person& person) {
    if (this->fullName != nullptr) delete[] this->fullName;
    if (this->homePhone != nullptr) delete[] this->homePhone;
    if (this->workPhone != nullptr) delete[] this->workPhone;
    if (this->mobilePhone != nullptr) delete[] this->mobilePhone;
    if (this->additionalInfo != nullptr) delete[] this->additionalInfo;

    this->fullName = new char[strlen(person.fullName) + 1];
    strcpy_s(this->fullName, strlen(person.fullName) + 1, person.fullName);

    this->homePhone = new char[strlen(person.homePhone) + 1];
    strcpy_s(this->homePhone, strlen(person.homePhone) + 1, person.homePhone);

    this->workPhone = new char[strlen(person.workPhone) + 1];
    strcpy_s(this->workPhone, strlen(person.workPhone) + 1, person.workPhone);

    this->mobilePhone = new char[strlen(person.mobilePhone) + 1];
    strcpy_s(this->mobilePhone, strlen(person.mobilePhone) + 1, person.mobilePhone);

    this->additionalInfo = new char[strlen(person.additionalInfo) + 1];
    strcpy_s(this->additionalInfo, strlen(person.additionalInfo) + 1, person.additionalInfo);
}