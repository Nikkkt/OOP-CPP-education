#pragma once
#include "ReportGenerator.hpp"
#include "Expense.hpp"
#include "Date.hpp"
#include <fstream>
#include <vector>
#include <map>

class Report {
private:
	std::map<Date, std::vector<Expense>> report;

public:
	Report(std::map<Date, std::vector<Expense>> report);

	void ShowDayReport(ReportGenerator rp, Date date, std::vector<Account*>& accounts);
	void ShowWeekReport(ReportGenerator rp, Date date, std::vector<Account*>& accounts);
	void ShowMonthReport(ReportGenerator rp, Date date, std::vector<Account*>& accounts);

	void AddToFileDayReport(ReportGenerator rp, Date date, std::vector<Account*>& accounts);
	void AddToFileWeekReport(ReportGenerator rp, Date date, std::vector<Account*>& accounts);
	void AddToFileMonthReport(ReportGenerator rp, Date date, std::vector<Account*>& accounts);

	void ShowWeekRatingByPrice(ReportGenerator rp, Date date, std::vector<Account*>& accounts);
	void ShowMonthRatingByPrice(ReportGenerator rp, Date date, std::vector<Account*>& accounts);
	void ShowWeekRatingByCategory(ReportGenerator rp, Date date, std::vector<Account*>& accounts);
	void ShowMonthRatingByCategory(ReportGenerator rp, Date date, std::vector<Account*>& accounts);

	void AddToFileWeekRatingByPrice(ReportGenerator rp, Date date, std::vector<Account*>& accounts);
	void AddToFileMonthRatingByPrice(ReportGenerator rp, Date date, std::vector<Account*>& accounts);
	void AddToFileWeekRatingByCategory(ReportGenerator rp, Date date, std::vector<Account*>& accounts);
	void AddToFileMonthRatingByCategory(ReportGenerator rp, Date date, std::vector<Account*>& accounts);
};