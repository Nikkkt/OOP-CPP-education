#pragma once
#include "Account.hpp"
#include "Expense.hpp"
#include <limits>
#include <string>
#include <vector>

class Wallet : public Account {
private:
	std::string WalletName;
	double CreditLimit;

public:
	Wallet();
	Wallet(std::string AccountHolder, std::string AccountNumber, double Balance, std::string WalletName, double CreditLimit, std::vector<Expense> Expenses);

	void Deposit(double Amount);
	void Withdraw(double Amount, Category ExpenseCategory, Date ExpenseDate, Time ExpenseTime);
	void Show();

	std::vector<Expense> getAllExpenses();
	std::vector<Expense> getExpensesByCategory(Category category);

	friend std::ostream& operator << (std::ostream& o, const Wallet& w);
	friend std::istream& operator >> (std::istream& i, Wallet& w);
};