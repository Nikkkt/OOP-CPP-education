#pragma once
#include <iostream>
#include "Expense.hpp"

class Account {
protected:
	std::string AccountHolder;
	std::string AccountNumber;
	std::vector<Expense> Expenses;
	double Balance;

public:
	Account();
	Account(std::string AccountHolder, std::string AccountNumber, double Balance, std::vector<Expense> Expenses);

	virtual void Deposit(double Amount) = 0;
	virtual void Withdraw(double Amount, Category ExpenseCategory, Date ExpenseDate, Time ExpenseTime) = 0;
	virtual void Show() = 0;

	virtual std::vector<Expense> getAllExpenses() = 0;
};