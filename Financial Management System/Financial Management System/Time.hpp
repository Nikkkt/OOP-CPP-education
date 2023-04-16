#pragma once

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
};

std::ostream& operator << (std::ostream& o, const Time& t);