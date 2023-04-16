#pragma once
#include <iostream>
#include "Date.hpp"
#include "Time.hpp"

class Expense {
private:
	double ExpenseAmount;
	std::string ExpenseCategory;
	Date ExpenseDate;
	Time ExpenseTime;

public:
	Expense();
	Expense(double ExpenseAmount, std::string ExpenseCategory, Date ExpenseDate, Time ExpenseTime);
	Expense(double ExpenseAmount, std::string ExpenseCategory, unsigned short day, unsigned short month, unsigned short year, unsigned short seconds, unsigned short minutes, unsigned short hours);

	double GetExpenseAmount() const;
	std::string GetExpenseCategory() const;
	Date GetExpenseDate() const;
	Time GetExpenseTime() const;
};

std::ostream& operator << (std::ostream& o, const Expense& e);