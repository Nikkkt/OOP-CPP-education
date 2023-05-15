#pragma once
#include <vector>
#include "Expense.hpp"
#include "Account.hpp"
#include "Date.hpp"

class ReportGenerator {
public:
	std::vector<Expense> generateDayReport(Date date, std::vector<Account*>& accounts);
	std::vector<Expense> generateWeekReport(Date date, std::vector<Account*>& accounts);
	std::vector<Expense> generateMonthReport(Date date, std::vector<Account*>& accounts);

	void ShowDayReport();
	void ShowWeekReport();
	void ShowMonthReport();

	void AddToFileDayReport();
	void AddToFileWeekReport();
	void AddToFileMonthReport();
};