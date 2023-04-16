#include "Account.hpp"
#include <iostream>

Account::Account() : AccountHolder("No name"), AccountNumber("AA00 AAAA 0000 0000 0000 0000"), Balance(0.0) {}

Account::Account(std::string AccountHolder, std::string AccountNumber, double Balance) : 
	AccountHolder(AccountHolder), AccountNumber(AccountNumber), Balance(Balance) {}