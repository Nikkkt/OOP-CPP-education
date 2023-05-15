#pragma once
#include "Account.hpp"
#include "Expense.hpp"
#include <vector>

class Card : public Account {
private:
	std::string CardName;
	double CreditLimit;

public:
	Card();
	Card(std::string AccountHolder, std::string AccountNumber, double Balance, std::string CardName, double CreditLimit, std::vector<Expense> Expenses);

	void Deposit(double Amount);
	void Withdraw(double Amount, Category ExpenseCategory, Date ExpenseDate, Time ExpenseTime);

	std::vector<Expense> getExpensesByCategory(Category category);
	std::vector<Expense> getAllExpenses();

	friend std::ostream& operator << (std::ostream& o, const Card& c);
	friend std::istream& operator >> (std::istream& i, Card& c);
};