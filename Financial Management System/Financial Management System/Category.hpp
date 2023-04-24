#pragma once
#include <iostream>
#include <vector>
#include "Expense.hpp"

class Category {
private:
	std::string Name;
	std::vector<Expense> Expenses;

public:
	Category();
	Category(std::string Name, std::vector<Expense> Expenses);

	void addExpense(Expense expense);
	double getTotalAmount();
	int getNumberOfExpenses();
};