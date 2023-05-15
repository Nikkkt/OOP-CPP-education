#include "Account.hpp"
#include <iostream>

Account::Account() : AccountHolder("No name"), AccountNumber("AA00 AAAA 0000 0000 0000 0000"), Balance(0.0) {
	std::vector<Expense> tmp;
	tmp.push_back(Expense());
	Expenses = tmp;
}

Account::Account(std::string AccountHolder, std::string AccountNumber, double Balance, std::vector<Expense> Expenses) :
	AccountHolder(AccountHolder), AccountNumber(AccountNumber), Balance(Balance), Expenses(Expenses) {}