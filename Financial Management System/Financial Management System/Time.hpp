#pragma once
#include <iostream>

class Time {
private:
	unsigned short seconds;
	unsigned short minutes;
	unsigned short hours;

public:
	Time();
	Time(unsigned short seconds, unsigned short minutes, unsigned short hours);

	void Show() const;
	void Init();

	short GetSeconds() const;
	short GetMinutes() const;
	short GetHours() const;

	void SetSeconds(unsigned short seconds);
	void SetMinutes(unsigned short minutes);
	void SetHours(unsigned short hours);
};

std::ostream& operator << (std::ostream& o, const Time& t);
std::istream& operator >> (std::istream& i, Time& t);