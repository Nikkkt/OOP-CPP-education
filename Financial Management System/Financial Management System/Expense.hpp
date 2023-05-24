#pragma once
#include <iostream>
#include <string>
#include "Date.hpp"
#include "Time.hpp"
#include "Category.hpp"

class Expense {
private:
	double ExpenseAmount;
	Category ExpenseCategory;
	Date ExpenseDate;
	Time ExpenseTime;

public:
	Expense();
	Expense(double ExpenseAmount, Category ExpenseCategory, Date ExpenseDate, Time ExpenseTime);
	Expense(double ExpenseAmount, std::string ExpenseCategoryName, double ExpenseCategoryCashback, unsigned short day, unsigned short month, unsigned short year, unsigned short seconds, unsigned short minutes, unsigned short hours);

	double GetExpenseAmount() const;
	Category GetExpenseCategory() const;
	Date GetExpenseDate() const;
	Time GetExpenseTime() const;

	std::string toString();

	void SetExpenseAmount(double ExpenseAmount);
	void SetExpenseCategory(Category ExpenseCategory);
	void SetExpenseDate(Date ExpenseDate);
	void SetExpenseTime(Time ExpenseTime);

	bool operator < (const Expense& e) const;
	bool operator > (const Expense& e) const;

	friend std::ostream& operator << (std::ostream& o, const Expense& e);
	friend std::istream& operator >> (std::istream& i, Expense& e);
};