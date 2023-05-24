#pragma once
#include "includes.hpp"

int diffBetweenDates(Date begin_date, Date end_date);

int menu();
int add();
void addcard(std::vector<Account*>& accounts);
void addwallet(std::vector<Account*>& accounts);
int list(std::vector<Account*>& accounts);
int actions(std::vector<Account*>& accounts, int number);
void replenishment(Account* account);
void addexpense(Account* account);
int reports();
int ratings();
Date dayreport();
Date weekreport();
Date monthreport();
int ByPriceOrByCategory();
int reportactions();