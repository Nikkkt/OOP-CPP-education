#include "Time.h"
#include <iostream>

Time::Time() { seconds = minutes = hours = 0; }

Time::Time(int seconds) {
    if (seconds < 0 || seconds > 59) { this->seconds = 0; }
    else { this->seconds = seconds; }
}

Time::Time(int seconds, int minutes): Time(seconds) {
    if (minutes < 0 || minutes > 59) { this->minutes = 0; }
    else { this->minutes = minutes; }
}

Time::Time(int seconds, int minutes, int hours): Time(seconds, minutes) {
    if (hours < 0 || hours > 23) { this->hours = 0; }
    else { this->hours = hours; }
}

int Time::GetSeconds() { return seconds; }
int Time::GetMinutes() { return minutes; }
int Time::GetHours() { return hours; }

void Time::SetSeconds(int seconds) {
    if (seconds < 0 || seconds > 59) { this->seconds = this->seconds; }
    else { this->seconds = seconds; }
}

void Time::SetMinutes(int minutes) {
    if (minutes < 0 || minutes > 59) { this->minutes = this->minutes; }
    else { this->minutes = minutes; }
}

void Time::SetHours(int hours) {
    if (hours < 0 || hours > 23) { this->hours = this->hours; }
    else { this->hours = hours; }
}

Time Time::operator + (int s) {
    Time tmp(this->seconds, this->minutes, this->hours);
    seconds += s;
    if (seconds > 59) {
        int n = seconds % 60;
        seconds -= 60 * n;
        minutes += n;
        if (minutes > 59) {
            int k = minutes % 60;
            minutes -= 60 * k;
            hours += k;
            if (hours > 23) {
                int m = hours % 24;
                hours -= 24 * m;
            }
        }
    }
    return tmp;
}

Time& Time::operator ++ () {
    seconds += 1;
    if (seconds > 59) { 
        minutes += 1;
        seconds = 0;
        if (minutes > 59) {
            hours += 1;
            minutes = 0;
            if (hours > 23) {
                hours = 0;
            }
        }
    }
    return *this;
}

Time& Time::operator -- () {
    seconds -= 1;
    if (seconds < 0) {
        minutes -= 1;
        seconds = 0;
        if (minutes < 0) {
            hours -= 1;
            minutes = 0;
            if (hours < 0) {
                hours = 0;
            }
        }
    }
    return *this;
}

Time Time::operator ++ (int) {
    Time tmp(this->seconds, this->minutes, this->hours);
    seconds += 1;
    if (seconds > 59) {
        minutes += 1;
        seconds = 0;
        if (minutes > 59) {
            hours += 1;
            minutes = 0;
            if (hours > 23) {
                hours = 0;
            }
        }
    }
    return tmp;
}

Time Time::operator -- (int) {
    Time tmp(this->seconds, this->minutes, this->hours);
    seconds -= 1;
    if (seconds < 0) {
        minutes -= 1;
        seconds = 0;
        if (minutes < 0) {
            hours -= 1;
            minutes = 0;
            if (hours < 0) {
                hours = 0;
            }
        }
    }
    return tmp;
}

bool Time::operator == (const Time& b) {
    if (seconds == b.seconds && minutes == b.minutes && hours == b.hours) { return true; }
    return false;
}

bool Time::operator != (const Time& b) {
    if (seconds == b.seconds && minutes == b.minutes && hours == b.hours) { return false; }
    return true;
}

bool Time::operator < (const Time& b) {
    if (hours < b.hours) { return true; }
    else if (hours == b.hours) {
        if (minutes < b.minutes) { return true; }
        else if (minutes == b.minutes) { if (seconds < b.seconds) return true; }
    }
    return false;
}

bool Time::operator <= (const Time& b) {
    if (hours < b.hours) { return true; }
    else if (hours == b.hours) {
        if (minutes < b.minutes) { return true; }
        else if (minutes == b.minutes) { if (seconds <= b.seconds) return true; }
    }
    return false;
}

bool Time::operator > (const Time& b) {
    if (hours > b.hours) { return true; }
    else if (hours == b.hours) {
        if (minutes > b.minutes) { return true; }
        else if (minutes == b.minutes) { if (seconds > b.seconds) return true; }
    }
    return false;
}

bool Time::operator >= (const Time& b) {
    if (hours > b.hours) { return true; }
    else if (hours == b.hours) {
        if (minutes > b.minutes) { return true; }
        else if (minutes == b.minutes) { if (seconds >= b.seconds) return true; }
    }
    return false;
}

std::ostream& operator << (std::ostream& o, const Time& t) {
    if (t.seconds < 10 && t.minutes < 10 && t.hours < 10) { o << "0" << t.seconds << ":0" << t.minutes << ":0" << t.hours; }
    else if (t.seconds < 10 && t.minutes < 10 && t.hours >= 10) { o << "0" << t.seconds << ":0" << t.minutes << ":" << t.hours; }
    else if (t.seconds < 10 && t.minutes >= 10 && t.hours >= 10) { o << "0" << t.seconds << ":" << t.minutes << ":" << t.hours; }
    else if (t.seconds >= 10 && t.minutes < 10 && t.hours >= 10) { o << t.seconds << ":0" << t.minutes << ":" << t.hours; }
    else if (t.seconds < 10 && t.minutes >= 10 && t.hours < 10) { o << "0" << t.seconds << ":" << t.minutes << ":0" << t.hours; }
    else if (t.seconds >= 10 && t.minutes < 10 && t.hours < 10) { o << t.seconds << ":0" << t.minutes << ":0" << t.hours; }
    else if (t.seconds >= 10 && t.minutes >= 10 && t.hours < 10) { o << t.seconds << ":" << t.minutes << ":0" << t.hours; }
    else { o << t.seconds << ":" << t.minutes << ":" << t.hours; }
    return o;
}

std::istream& operator >> (std::istream& i, Time& t) {
    init:
        char c1, c2;
        std::cout << "Enter time in format ss:mm:hh -> ";
        std::cin >> t.seconds >> c1 >> t.minutes >> c2 >> t.hours;
        if (c1 != ':' || c2 != ':' || 
            t.seconds < 0 || t.seconds > 59 ||
            t.minutes < 0 || t.minutes > 59 ||
            t.hours < 0 || t.hours > 23) {
            goto init;
        }
    return i;
}