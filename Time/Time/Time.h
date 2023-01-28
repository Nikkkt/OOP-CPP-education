#pragma once
#include <iostream>

class Time {
private:
	int seconds;
	int minutes;
	int hours;

	Time(int seconds);
	Time(int seconds, int minutes);

public:
	Time();
	Time(int seconds, int minutes, int hours);

	int GetSeconds();
	int GetMinutes();
	int GetHours();

	void SetSeconds(int seconds);
	void SetMinutes(int minutes);
	void SetHours(int hours);

	Time operator + (int s);

	Time& operator ++ ();
	Time& operator -- ();

	Time operator ++ (int);
	Time operator -- (int);

	bool operator == (const Time& b);
	bool operator != (const Time& b);

	bool operator < (const Time& b);
	bool operator <= (const Time& b);

	bool operator > (const Time& b);
	bool operator >= (const Time& b);

	friend std::ostream& operator << (std::ostream& o, const Time& t);
	friend std::istream& operator >> (std::istream& i, Time& t);
};