#pragma once

struct Elem {
    char fullName[50];
    double average;

    Elem* Parent;
    Elem* Left;
    Elem* Right;

    char* GetFullName();
    double GetAverage();
};