#include <iostream>
#include "Date.h"

Date::Date() { day = month = year = 0; }
Date::Date(int day) { 
	if (day < 0 ||
		((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31) || 
		((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) ||
		(month == 2 && year % 4 != 0 && day > 28) ||
		(month == 2 && year % 4 == 0 && day > 29)) {
		this->day = 0;
	}
	else {
		this->day = day;
	}
}
Date::Date(int day, int month): Date(day) { 
	if (month < 0 || month > 12) { this->month = 0; }
	else { this->month = month; }
}
Date::Date(int day, int month, int year): Date(day, month) { this->year = year; }

void Date::Print() { printf("%02d.%02d.%d\n", day, month, year); }

void Date::Init() {
	char c1, c2;
	std::cout << "Enter date in xx.xx.xxxx format -> ";
	std::cin >> day >> c1 >> month >> c2 >> year;
	if (c1 != '.' || c2 != '.' || day < 0 || month < 0 || month > 12 ||
		((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31) ||
		((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) ||
		(month == 2 && year % 4 != 0 && day > 28) ||
		(month == 2 && year % 4 == 0 && day > 29)) {
		Init();
	}
}

int Date::GetDay() const { return day; }
int Date::GetMonth() const { return month; }
int Date::GetYear() const { return year; }

void Date::SetDay(int day) {
	if (day < 0 || 
		((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31) ||
		((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) ||
		(month == 2 && year % 4 != 0 && day > 28) ||
		(month == 2 && year % 4 == 0 && day > 29)) {this->day = this->day; }
	else { this->day = day; }
}

void Date::SetMonth(int month) {
	if (month < 0 || month > 12) { this->month = this->month; }
	else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31) {
		day = 31;
		this->month = month;
	}
	else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
		day = 30;
		this->month = month;
	}
	else if ((month == 2 && year % 4 != 0 && day > 28)) {
		day = 28;
		this->month = month;
	}
	else if ((month == 2 && year % 4 == 0 && day > 29)) {
		day = 29;
		this->month = month;
	}
	else { this->month = month; }
}

void Date::SetYear(int year) { this->year = year;}

Date& Date::operator ++ () {
	day += 1;
	if (((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31) ||
		((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) ||
		(month == 2 && year % 4 != 0 && day > 28) ||
		(month == 2 && year % 4 == 0 && day > 29)) {
		day = 1;
		month += 1;
	}
	if (month > 12) {
		month = 1;
		year += 1;
	}
	return *this;
}

Date& Date::operator -- () {
	day -= 1;
	if (day < 1) {
		day = 1;
		month -= 1;
	}
	if (month < 1) {
		month = 1;
		year -= 1;
	}
	return *this;
}

Date Date::operator ++ (int) {
	Date tmp(this->day, this->month, this->year);
	day += 1;
	if (((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31) ||
		((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) ||
		(month == 2 && year % 4 != 0 && day > 28) ||
		(month == 2 && year % 4 == 0 && day > 29)) {
		day = 1;
		month += 1;
	}
	if (month > 12) {
		month = 1;
		year += 1;
	}
	return tmp;
}

Date Date::operator -- (int) {
	Date tmp(this->day, this->month, this->year);
	day -= 1;
	if (day < 1) {
		day = 1;
		month -= 1;
	}
	if (month < 1) {
		month = 1;
		year -= 1;
	}
	return tmp;
}

Date Date::operator + (int b) {
	Date tmp(this->day, this->month, this->year);
	day += b;
	if (((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31)) {
		day -= 31;
		month += 1;
	}
	else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
		day -= 30;
		month += 1;
	}
	else if ((month == 2 && year % 4 != 0 && day > 28)) {
		day -= 28;
		month += 1;
	}
	else if ((month == 2 && year % 4 == 0 && day > 29)) {
		day -= 29;
		month += 1;
	}
	if (month > 12) {
		month = 1;
		year += 1;
	}
	return tmp;
}

Date Date::operator - (int b) {
	Date tmp(this->day, this->month, this->year);
	day -= b;
	if (((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day < 0)) {
		day += 31;
		month -= 1;
	}
	else if ((month == 4 || month == 6 || month == 9 || month == 11) && day < 0) {
		day += 30;
		month -= 1;
	}
	else if ((month == 2 && year % 4 != 0 && day < 0)) {
		day += 28;
		month -= 1;
	}
	else if ((month == 2 && year % 4 == 0 && day < 0)) {
		day += 29;
		month -= 1;
	}
	if (month < 1) {
		month = 12;
		year -= 1;
	}
	return tmp;
}

Date Date::operator - (Date b) {
	Date tmp(this->day, this->month, this->year);
	day -= b.day;
	month -= b.month;
	year -= b.year;
	if (((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day < 0)) {
		day += 31;
		month -= 1;
	}
	else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
		day += 30;
		month -= 1;
	}
	else if ((month == 2 && year % 4 != 0 && day > 28)) {
		day += 28;
		month -= 1;
	}
	else if ((month == 2 && year % 4 == 0 && day > 29)) {
		day += 29;
		month -= 1;
	}
	if (month < 1) {
		month = 12;
		year -= 1;
	}
	return tmp;
}

Date& Date::operator += (int b) {
	day += b;
	if (((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31)) {
		day -= 31;
		month += 1;
	}
	else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
		day -= 30;
		month += 1;
	}
	else if ((month == 2 && year % 4 != 0 && day > 28)) {
		day -= 28;
		month += 1;
	}
	else if ((month == 2 && year % 4 == 0 && day > 29)) {
		day -= 29;
		month += 1;
	}
	if (month > 12) {
		month = 1;
		year += 1;
	}
	return *this;
}

Date& Date::operator -= (int b) {
	day -= b;
	if (((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day < 0)) {
		day += 31;
		month -= 1;
	}
	else if ((month == 4 || month == 6 || month == 9 || month == 11) && day < 0) {
		day += 30;
		month -= 1;
	}
	else if ((month == 2 && year % 4 != 0 && day < 0)) {
		day += 28;
		month -= 1;
	}
	else if ((month == 2 && year % 4 == 0 && day < 0)) {
		day += 29;
		month -= 1;
	}
	if (month < 1) {
		month = 12;
		year -= 1;
	}
	return *this;
}

bool Date::operator == (const Date& b) {
	if (day == b.day && month == b.month && year == b.year) { return true; }
	return false;
}

bool Date::operator != (const Date& b) {
	if (day == b.day && month == b.month && year == b.year) { return false; }
	return true;
}

bool Date::operator < (const Date& b) {
	if (year < b.year) { return true; }
	else if (year == b.year) {
		if (month < b.month) { return true; }
		else if (month == b.month) {
			if (day < b.day) { return true; }
		}
	}
	return false;
}

bool Date::operator <= (const Date& b) {
	if (year < b.year) { return true; }
	else if (year == b.year) {
		if (month < b.month) { return true; }
		else if (month == b.month) {
			if (day < b.day || day == b.day) { return true; }
		}
	}
	return false;
}

bool Date::operator > (const Date& b) {
	if (year > b.year) { return true; }
	else if (year == b.year) {
		if (month > b.month) { return true; }
		else if (month == b.month) {
			if (day > b.day) { return true; }
		}
	}
	return false;
}

bool Date::operator >= (const Date& b)
{
	if (year > b.year) { return true; }
	else if (year == b.year) {
		if (month > b.month) { return true; }
		else if (month == b.month) {
			if (day > b.day || day == b.day) { return true; }
		}
	}
	return false;
}

int Date::operator [] (int index) {
	if (index == 0 || index == -3) return day;
	else if (index == 1 || index == -2) return month;
	else if (index == 2 || index == -1) return year;
	else throw "OOPS!";
	return 0;
}

std::ostream& operator << (std::ostream& o, const Date& d) {
	if (d.day < 10 && d.month < 10) { o << "0" << d.day << ".0" << d.month << "." << d.year; }
	else if (d.day < 10 && d.month > 10) { o << "0" << d.day << "." << d.month << "." << d.year; }
	else if (d.day > 10 && d.month < 10) { o << d.day << ".0" << d.month << "." << d.year; }
	else { o << d.day << "." << d.month << "." << d.year; }
	return o;
}

std::istream& operator>>(std::istream& i, Date& d) {
	init:
		char c1, c2;
		std::cout << "Enter date in xx.xx.xxxx format -> ";
		std::cin >> d.day >> c1 >> d.month >> c2 >> d.year;
		if (c1 != '.' || c2 != '.' || d.day < 0 || d.month < 0 || d.month > 12 ||
			((d.month == 1 || d.month == 3 || d.month == 5 || d.month == 7 || d.month == 8 || d.month == 10 || d.month == 12) && d.day > 31) ||
			((d.month == 4 || d.month == 6 || d.month == 9 || d.month == 11) && d.day > 30) ||
			(d.month == 2 && d.year % 4 != 0 && d.day > 28) ||
			(d.month == 2 && d.year % 4 == 0 && d.day > 29)) {
			goto init;
		}
	return i;
}