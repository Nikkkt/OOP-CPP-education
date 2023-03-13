#pragma once
#include "Student.h"

class StepStudent : public Student {
private:
	unsigned int technologies;

public:
	StepStudent();
	StepStudent(unsigned int technologies);

	void Show();
};