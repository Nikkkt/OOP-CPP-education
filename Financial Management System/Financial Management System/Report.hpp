#pragma once
#include "ReportGenerator.h"
#include "Expense.hpp"
#include "Date.hpp"
#include <vector>
#include <map>

class Report {
private:
	std::map<Date, std::vector<Expense>> Report;

public:
	void ShowDayReport(ReportGenerator rp);
	void ShowWeekReport(ReportGenerator rp);
	void ShowMonthReport(ReportGenerator rp);

	void AddToFileDayReport(ReportGenerator rp);
	void AddToFileWeekReport(ReportGenerator rp);
	void AddToFileMonthReport(ReportGenerator rp);
};