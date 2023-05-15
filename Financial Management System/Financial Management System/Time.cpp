#include "Time.hpp"
#include <iostream>
#include <iomanip>

Time::Time() : seconds(0), minutes(0), hours(0) {}

Time::Time(unsigned short seconds, unsigned short minutes, unsigned short hours) : seconds(seconds), minutes(minutes), hours(hours) {}

void Time::Show() const {
	std::cout << std::setw(2) << std::setfill('0') << hours << ":"
		<< std::setw(2) << std::setfill('0') << minutes << ":"
		<< std::setw(2) << std::setfill('0') << seconds << std::endl;
}

void Time::Init() {
	char colon1, colon2;
	std::cout << "Enter Time in format hh:mm:ss >> ";
	std::cin >> seconds >> colon1 >> minutes >> colon2 >> hours;
	if (colon1 != ':' || colon2 != ':' || seconds < 0 || seconds > 59 || minutes < 0 || minutes > 59 || hours < 0 || hours > 23) {
		system("cls");
		Init();
	}
}

short Time::GetSeconds() const { return seconds; }
short Time::GetMinutes() const { return minutes; }
short Time::GetHours() const { return hours; }

void Time::SetSeconds(unsigned short seconds) { this->seconds = seconds; }
void Time::SetMinutes(unsigned short minutes) { this->minutes = minutes; }
void Time::SetHours(unsigned short hours) { this->hours = hours; }

std::ostream& operator << (std::ostream& o, const Time& t) {
	o << std::setw(2) << std::setfill('0') << t.GetHours() << ":" 
		<< std::setw(2) << std::setfill('0') << t.GetMinutes() << ":" 
		<< std::setw(2) << std::setfill('0') << t.GetSeconds();
	return o;
}

std::istream& operator >> (std::istream& i, Time& t) {
	char colon1, colon2;
	unsigned short seconds, minutes, hours;
	INIT:
		std::cout << "Enter Time in format hh:mm:ss >> ";
		std::cin >> seconds >> colon1 >> minutes >> colon2 >> hours;
		if (colon1 != ':' || colon2 != ':' || seconds < 0 || seconds > 59 || minutes < 0 || minutes > 59 || hours < 0 || hours > 23) {
			system("cls");
			goto INIT;
		}
		t.SetSeconds(seconds);
		t.SetMinutes(minutes);
		t.SetHours(hours);
	return i;
}