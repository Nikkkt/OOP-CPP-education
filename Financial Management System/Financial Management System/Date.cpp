#include "Date.hpp"
#include <iostream>
#include <iomanip>

Date::Date(): day(0), month(0), year(0) {}

Date::Date(unsigned short day, unsigned short month, unsigned short year) : day(day), month(month), year(year) {}

void Date::Show() const {
	std::cout << std::setw(2) << std::setfill('0') << day << "."
		<< std::setw(2) << std::setfill('0') << month << "."
		<< std::setw(2) << std::setfill('0') << year << std::endl;
}

void Date::Init() {
	char dot1, dot2;
	std::cout << "Enter date in format DD.MM.YYYY >> ";
	std::cin >> day >> dot1 >> month >> dot2 >> year;
	if (dot1 != '.' || dot2 != '.' || day < 0 || month < 0 || month > 12 ||
		((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31) ||
		((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) ||
		(month == 2 && year % 4 != 0 && day > 28) ||
		(month == 2 && year % 4 == 0 && day > 29)) {
		system("cls");
		Init();
	}
}

short Date::GetDay() const { return day; }
short Date::GetMonth() const { return month; }
short Date::GetYear() const { return year; }

bool Date::isLeap() const { return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0; }

int Date::daysInYear() const { return isLeap() ? 366 : 365; }

int Date::daysInMonth() const {
	if (month == 2) return isLeap() ? 29 : 28;
	else if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
	return 31;
}

int Date::daysFromBegin() const {
	int tmp = 0;
	for (int y = 0; y < year; y++) tmp += Date(1, 1, y).daysInYear();
	for (int m = 1; m < month; m++) tmp += Date(1, m, year).daysInMonth();
	tmp += day - 1;
	return tmp;
}

std::ostream& operator << (std::ostream& o, const Date& d) {
	o << std::setw(2) << std::setfill('0') << d.GetDay() << "."
		<< std::setw(2) << std::setfill('0') << d.GetMonth() << "."
		<< std::setw(2) << std::setfill('0') << d.GetYear();
	return o;
}