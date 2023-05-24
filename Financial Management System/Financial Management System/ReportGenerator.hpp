#pragma once
#include <vector>
#include <map>
#include "Expense.hpp"
#include "Account.hpp"
#include "Date.hpp"

class ReportGenerator {
public:
	ReportGenerator();

	std::map<Date, std::vector<Expense>> generateDayReport(Date date, std::vector<Account*>& accounts);
	std::map<Date, std::vector<Expense>> generateWeekReport(Date date, std::vector<Account*>& accounts);
	std::map<Date, std::vector<Expense>> generateMonthReport(Date date, std::vector<Account*>& accounts);
};