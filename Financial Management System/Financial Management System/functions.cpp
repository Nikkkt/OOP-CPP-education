#include "functions.hpp"

int diffBetweenDates(Date beginDate, Date endDate) { return endDate.daysFromBegin() - beginDate.daysFromBegin(); }

int menu() {
	system("cls");
	int choice;
	std::cout << "Financial Management System" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << "1. Show all cards and wallets" << std::endl;
	std::cout << "2. Add new card" << std::endl;
	std::cout << "3. Exit" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << "Enter your choice >> ";
	std::cin >> choice;
	return choice;
}

int add() {
	system("cls");
	int choice;
	std::cout << "Financial Management System" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << "What you want to add?" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << "1. Card" << std::endl;
	std::cout << "2. Wallet" << std::endl;
	std::cout << "3. Exit" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << "Enter your choice >> ";
	std::cin >> choice;
	return choice;
}

void addcard(std::vector<Account*>& accounts) {
	system("cls");
	Card NewCard;
	std::cout << "Financial Management System" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cin >> NewCard;
	accounts.push_back(new Card(NewCard));
	Sleep(1000);
	system("cls");
	std::cout << "New card added!" << std::endl;
	std::cout << "Wait 2 seconds for returning to main menu :)" << std::endl;
	Sleep(2000);
	system("cls");
}

void addwallet(std::vector<Account*>& accounts) {
	system("cls");
	Wallet NewWallet;
	std::cout << "Financial Management System" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cin >> NewWallet;
	accounts.push_back(new Wallet(NewWallet));
	Sleep(1000);
	system("cls");
	std::cout << "New wallet added!" << std::endl;
	std::cout << "Wait 2 seconds for returning to main menu :)" << std::endl;
	Sleep(2000);
	system("cls");
}

int list(std::vector<Account*>& accounts) {
	system("cls");
	if (accounts.size() == 0) {
		std::cout << "Financial Management System" << std::endl;
		std::cout << "-----------------------------" << std::endl;
		std::cout << "Sorry, there is no any wallets or cards :(" << std::endl;
		std::cout << "Returning in 3 seconds..." << std::endl;
		Sleep(3000);
		return 0;
	}
	int choice;
	std::cout << "Financial Management System" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << "Which wallet/card do you want to work with?" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	for (int i = 0; i < accounts.size(); i++) {
		std::cout << i + 1 << ".";
		accounts[i]->Show();
	}
	std::cout << "Enter your choice (to exit enter 0) >> ";
	std::cin >> choice;
	return choice;
}

int actions(std::vector<Account*>& accounts, int number) {
	system("cls");
	int choice;
	std::cout << "Financial Management System" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	accounts[number - 1]->Show();
	std::cout << "What you want to do?" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << "1. Replenishment" << std::endl;
	std::cout << "2. Add expense" << std::endl;
	std::cout << "3. Generate report" << std::endl;
	std::cout << "4. Generate rating" << std::endl;
	std::cout << "5. Exit" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << "Enter your choice >> ";
	std::cin >> choice;
	return choice;
}

void replenishment(Account* account) {
	system("cls");
	int sum;
	std::cout << "Financial Management System" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << "What amount of money you want to replenishment on your account?" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << "Enter amount >> ";
	std::cin >> sum;
	system("cls");
	std::cout << "Wait 2 seconds, please :)" << std::endl;
	account->Deposit(sum);
	Sleep(2000);
}

void addexpense(Account* account) {
	system("cls");
	Expense tmp;
	std::cout << "Financial Management System" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cin >> tmp;
	std::cout << "-----------------------------" << std::endl;
	system("cls");
	std::cout << "Wait 2 seconds, please :)" << std::endl;
	account->Withdraw(tmp.GetExpenseAmount(), tmp.GetExpenseCategory(), tmp.GetExpenseDate(), tmp.GetExpenseTime());
	Sleep(2000);
}

int reports() {
	system("cls");
	int choice;
	std::cout << "Financial Management System" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << "What you want to do?" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << "1. Generate day report" << std::endl;
	std::cout << "2. Generate week report" << std::endl;
	std::cout << "3. Generate month report" << std::endl;
	std::cout << "4. Exit" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << "Enter your choice >> ";
	std::cin >> choice;
	return choice;
}

int ratings() {
	system("cls");
	int choice;
	std::cout << "Financial Management System" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << "What you want to do?" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << "1. Show week rating" << std::endl;
	std::cout << "2. Show month rating" << std::endl;
	std::cout << "3. Add to file week rating" << std::endl;
	std::cout << "4. Add to file month rating" << std::endl;
	std::cout << "5. Exit" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << "Enter your choice >> ";
	std::cin >> choice;
	return choice;
}

Date dayreport() {
	system("cls");
	std::cout << "Financial Management System" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << "Day report (enter date)" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	Date tmp;
	std::cin >> tmp;
	return tmp;
}

Date weekreport() {
	system("cls");
	std::cout << "Financial Management System" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << "Day report (enter end date)" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	Date tmp;
	std::cin >> tmp;
	return tmp;
}

Date monthreport() {
	system("cls");
	std::cout << "Financial Management System" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << "Day report (enter date)" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	Date tmp;
	std::cin >> tmp;
	return tmp;
}

int ByPriceOrByCategory() {
	system("cls");
	int choice;
	std::cout << "Financial Management System" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << "Which rating do you want to do?" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << "1. By Price" << std::endl;
	std::cout << "2. By Category" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << "Enter your choice >> ";
	std::cin >> choice;
	return choice;
}

int reportactions() {
	system("cls");
	int choice;
	std::cout << "Financial Management System" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << "What you want to do?" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << "1. Show report" << std::endl;
	std::cout << "2. Add to file report" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << "Enter your choice >> ";
	std::cin >> choice;
	return choice;
}