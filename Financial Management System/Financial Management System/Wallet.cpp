#include "Wallet.hpp"

Wallet::Wallet() : Account(), WalletName("No bank title"), CreditLimit(0.0) {}

Wallet::Wallet(std::string AccountHolder, std::string AccountNumber, double Balance, std::string WalletName, double CreditLimit, std::vector<Expense> Expenses) :
	Account(AccountHolder, AccountNumber, Balance, Expenses), WalletName(WalletName), CreditLimit(CreditLimit) {}

void Wallet::Deposit(double Amount) { Balance += Amount; }

void Wallet::Withdraw(double Amount, Category ExpenseCategory, Date ExpenseDate, Time ExpenseTime) {
	Balance -= Amount;
	if (Balance < 0) {
		if (Balance < CreditLimit) {
			Balance += Amount;
			std::cout << "Expense is too big";
		}
	}
	Balance += Amount * (ExpenseCategory.GetCategoryCashback() / 100);
	Expense tmp(Amount, ExpenseCategory, ExpenseDate, ExpenseTime);
	Expenses.push_back(tmp);
}

void Wallet::Show() {
	std::cout << "-----------------------------" << std::endl
		<< "Wallet " << WalletName << ":" << std::endl
		<< " Balance: " << Balance << std::endl
		<< " Credit limit: " << CreditLimit << std::endl
		<< "Holder: " << std::endl
		<< " Name: " << AccountHolder << std::endl
		<< " Wallet number: " << AccountNumber << std::endl
		<< "-----------------------------" << std::endl;
}

std::vector<Expense> Wallet::getExpensesByCategory(Category category) {
	std::vector<Expense> tmp;
	for (int i = 0; i < Expenses.size(); i++) if (Expenses[i].GetExpenseCategory() == category) tmp.push_back(Expenses[i]);
	return tmp;
}

std::vector<Expense> Wallet::getAllExpenses() { return Expenses; }

std::ostream& operator << (std::ostream& o, const Wallet& w) {
	o << "-----------------------------" << std::endl
		<< "Wallet " << w.WalletName << ":" << std::endl
		<< " Balance: " << w.Balance << std::endl
		<< " Credit limit: " << w.CreditLimit << std::endl
		<< "Holder: " << std::endl
		<< " Name: " << w.AccountHolder << std::endl
		<< " Wallet number: " << w.AccountNumber << std::endl
		<< "-----------------------------";
	return o;
}

std::istream& operator >> (std::istream& i, Wallet& w) {
	std::cout << "New wallet:" << std::endl
		<< " Account holder >> ";
	i.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(i, w.AccountHolder);

	std::cout << " Account number >> ";
	getline(i, w.AccountNumber);

	std::cout << " Balance >> ";
	i >> w.Balance;

	std::cout << " Credit limit (if wallet is debit enter 0) >> ";
	i >> w.CreditLimit;

	std::cout << " Bank name >> ";
	i.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(i, w.WalletName);

	std::vector<Expense> tmp;
	tmp.push_back(Expense());
	w.Expenses = tmp;

	return i;
}