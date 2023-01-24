#include "Account.h"
#include <iostream>

Account::Account() {
	name = nullptr;
	surname = nullptr;
	checkNumber = 0;
	percent = 0.0;
	sum = 0.0;
}

Account::Account(const char* name, const char* surname, int checkNumber, double percent, double sum): 
	checkNumber(checkNumber), percent(percent), sum(sum) {
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
	this->surname = new char[strlen(surname) + 1];
	strcpy_s(this->surname, strlen(surname) + 1, surname);
}

Account::Account(const Account& copy): checkNumber(copy.checkNumber), percent(copy.percent), sum(copy.sum) {
	name = new char[strlen(copy.name) + 1];
	strcpy_s(name, strlen(copy.name) + 1, copy.name);
	surname = new char[strlen(copy.surname) + 1];
	strcpy_s(surname, strlen(copy.surname) + 1, copy.surname);
}

Account::~Account() {
	delete[] name;
	delete[] surname;
}

void Account::setName(const char* name) {
	if (name != nullptr) delete[] name;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}
void Account::setSurname(const char* surname) {
	if (surname != nullptr) delete[] surname;
	this->surname = new char[strlen(surname) + 1];
	strcpy_s(this->surname, strlen(surname) + 1, surname);
}
void Account::setCheckNumber(int checkNumber) { this->checkNumber = checkNumber; }
void Account::setPercent(double percent) { this->percent = percent; }
void Account::setSum(double sum) { this->sum = sum; }

const char* Account::getName() const { return name; }
const char* Account::getSurname() const { return surname; }
int Account::getCheckNumber() const { return checkNumber; }
double Account::getPercent() const { return percent; }
double Account::getSum() const { return sum; }

void Account::showInfo() {
	printf("Name: %s\nSurname: %s\nCheck number: %d\nPercent: %.02f%%\nSum: %.02f UAH\n", name, surname, checkNumber, percent, sum);
}

void Account::initAccount() {
	char buff[100];
	std::cout << "Enter name -> ";
	std::cin.getline(buff, 100);
	name = new char[strlen(buff) + 1];
	strcpy_s(name, strlen(buff) + 1, buff);

	std::cout << "Enter surname -> ";
	std::cin.getline(buff, 100);
	surname = new char[strlen(buff) + 1];
	strcpy_s(surname, strlen(buff) + 1, buff);

	std::cout << "Enter check number -> ";
	std::cin >> checkNumber;

	std::cout << "Enter percent -> ";
	std::cin >> percent;

	std::cout << "Enter sum -> ";
	std::cin >> sum;
}

void Account::changeOfOwnership(const char* newOwnerName, const char* newOwnerSurname) {
	if (name != nullptr) delete[] name;
	name = new char[strlen(newOwnerName) + 1];
	strcpy_s(name, strlen(newOwnerName) + 1, newOwnerName);

	if (surname != nullptr) delete[] surname;
	surname = new char[strlen(newOwnerSurname) + 1];
	strcpy_s(surname, strlen(newOwnerSurname) + 1, newOwnerSurname);
}

void Account::withdrawMoney(int amount) {
	if (amount > sum) {
		std::cout << "Not enough money!" << std::endl;
	}
	else {
		sum -= amount;
		std::cout << "All is OK. Your balance: " << sum << std::endl;
	}
}

void Account::addMoney(int amount) {
	sum += amount;
	std::cout << "All is OK. Your balance: " << sum << std::endl;
}

void Account::addPercents(double percents) {
	percent += percents;
	std::cout << "All is OK. Your percents: " << percent << std::endl;
}

double Account::toUSD() {
	std::cout << "Your balance in USD: " << sum / 37.0 << std::endl;
	return sum / 37.0;
}

double Account::toEUR() {
	std::cout << "Your balance in EUR: " << sum / 39.0 << std::endl;
	return sum / 39.0;
}

std::ostream& operator<<(std::ostream& o, const Account& a) {
	o << "Name: " << a.getName() << std::endl <<
		"Surname: " << a.getSurname() << std::endl <<
		"Check number: " << a.getCheckNumber() << std::endl <<
		"Percent: " << a.getPercent() << "%" << std::endl <<
		"Sum: " << a.getSum() << " UAH";
	return o;
}