#include "Card.hpp"

Card::Card() : Account(), CardName("No bank title"), CreditLimit(0.0) {}

Card::Card(std::string AccountHolder, std::string AccountNumber, double Balance, std::string CardName, double CreditLimit, std::vector<Expense> Expenses) :
	Account(AccountHolder, AccountNumber, Balance, Expenses), CardName(CardName), CreditLimit(CreditLimit) {}

void Card::Deposit(double Amount) { Balance += Amount; }

void Card::Withdraw(double Amount, Category ExpenseCategory, Date ExpenseDate, Time ExpenseTime) {
	Balance -= Amount;
	if (Balance < 0) {
		if (Balance < CreditLimit) {
			Balance += Amount;
			std::cout << "Expense is too big";
		}
	}
	Expense tmp(Amount, ExpenseCategory, ExpenseDate, ExpenseTime);
	Expenses.push_back(tmp);
}

std::vector<Expense> Card::getExpensesByCategory(Category category) {
	std::vector<Expense> tmp;
	for (int i = 0; i < Expenses.size(); i++) if (Expenses[i].GetExpenseCategory() == category) tmp.push_back(Expenses[i]);
	return tmp;
}

std::vector<Expense> Card::getAllExpenses() { return Expenses; }

std::ostream& operator << (std::ostream& o, const Card& c) {
	o << "-----------------------------" << std::endl
		<< "Card " << c.CardName << ":" << std::endl
		<< " Balance: " << c.Balance << std::endl
		<< " Credit limit: " << c.CreditLimit << std::endl
		<< "Holder: " << std::endl
		<< " Name" << c.AccountHolder << std::endl
		<< " Card number: " << c.AccountNumber << std::endl
		<< "-----------------------------";
	return o;
}

std::istream& operator >> (std::istream& i, Card& c) {
	std::cout << "New Card:" << std::endl
		<< " Account holder >> ";
	i >> c.AccountHolder;

	std::cout << " Account number >> ";
	i >> c.AccountNumber;

	std::cout << " Balance >> ";
	i >> c.Balance;

	std::cout << " Credit limit (if card is debit enter 0) >> ";
	i >> c.CreditLimit;

	std::cout << " Bank name >> ";
	i >> c.CardName;

	std::vector<Expense> tmp;
	tmp.push_back(Expense());
	c.Expenses = tmp;

	return i;
}