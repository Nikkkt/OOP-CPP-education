#pragma once
#include <iostream>

class Account {
private:
	std::string AccountHolder;
	std::string AccountNumber;
	double Balance;

public:
	Account();
	Account(std::string AccountHolder, std::string AccountNumber, double Balance);

	virtual void Deposit(double Amount) = 0;
	virtual void Withdraw(double Amount) = 0;
};