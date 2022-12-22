#include <iostream>
#include "Person.h"

Person::Person() {
	this->FullName = nullptr;
	this->HomePhone = nullptr;
	this->WorkPhone = nullptr;
	this->MobilePhone = nullptr;
	this->AdditionalInfo = nullptr;
}

Person::Person(const char* FullName, const char* HomePhone, const char* WorkPhone, const char* MobilePhone, const char* AdditionalInfo) {
	this->FullName = new char[std::strlen(FullName) + 1];
	strcpy_s(this->FullName, strlen(FullName) + 1, FullName);

	this->HomePhone = new char[std::strlen(HomePhone) + 1];
	strcpy_s(this->HomePhone, strlen(HomePhone) + 1, HomePhone);

	this->WorkPhone = new char[std::strlen(WorkPhone) + 1]; 
	strcpy_s(this->WorkPhone, strlen(WorkPhone) + 1, WorkPhone);

	this->MobilePhone = new char[std::strlen(MobilePhone) + 1]; 
	strcpy_s(this->MobilePhone, strlen(MobilePhone) + 1, MobilePhone);

	this->AdditionalInfo = new char[std::strlen(AdditionalInfo) + 1];
	strcpy_s(this->AdditionalInfo, strlen(AdditionalInfo) + 1, AdditionalInfo);
}

Person::~Person() {
	delete[] FullName;
	delete[] HomePhone;
	delete[] WorkPhone;
	delete[] MobilePhone;
	delete[] AdditionalInfo;
}

void Person::Init() {
	char buf[1000];
	std::cout << "Enter full name -> ";
	std::cin.getline(buf, 1000);
	if (FullName != nullptr) delete[] FullName;
	FullName = new char[std::strlen(buf) + 1];
	strcpy_s(FullName, std::strlen(buf) + 1, buf);

	char buf[1000];
	std::cout << "Enter home phone -> ";
	std::cin.getline(buf, 1000);
	if (HomePhone != nullptr) delete[] HomePhone;
	HomePhone = new char[std::strlen(buf) + 1];
	strcpy_s(HomePhone, std::strlen(buf) + 1, buf);

	char buf[1000];
	std::cout << "Enter work phone -> ";
	std::cin.getline(buf, 1000);
	if (WorkPhone != nullptr) delete[] WorkPhone;
	WorkPhone = new char[std::strlen(buf) + 1];
	strcpy_s(WorkPhone, std::strlen(buf) + 1, buf);

	char buf[1000];
	std::cout << "Enter mobile phone -> ";
	std::cin.getline(buf, 1000);
	if (MobilePhone != nullptr) delete[] MobilePhone;
	MobilePhone = new char[std::strlen(buf) + 1];
	strcpy_s(MobilePhone, std::strlen(buf) + 1, buf);

	char buf[1000];
	std::cout << "Enter additional info -> ";
	std::cin.getline(buf, 1000);
	if (AdditionalInfo != nullptr) delete[] AdditionalInfo;
	AdditionalInfo = new char[std::strlen(buf) + 1];
	strcpy_s(AdditionalInfo, std::strlen(buf) + 1, buf);
}

void Person::Print() {
	printf("Full name: %s\nHome phone: %s\nWork phone: %s\nMobile phone: %s\nAdditional info: %s\n", FullName, HomePhone, WorkPhone, MobilePhone, AdditionalInfo);
}