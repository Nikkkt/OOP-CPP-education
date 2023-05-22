#include "ReportGenerator.h"
#include <algorithm>

ReportGenerator::ReportGenerator() {}

std::map<Date, std::vector<Expense>> ReportGenerator::generateDayReport(Date date, std::vector<Account*>& accounts) {
	std::vector<Expense> report;
	int count = report.size();
	for (int i = 0; i < accounts.size(); i++) {
		for (int j = 0; j < accounts[i]->getAllExpenses().size(); j++) {
			if (accounts[i]->getAllExpenses()[j].GetExpenseDate() == date) {
				report.push_back(accounts[i]->getAllExpenses()[j]);
			}
		}
	}
	while (count--) {
		bool IsSwapped = false;
		for (int i = 0; i < count; i++) {
			if (report[i] > report[i + 1]) {
				std::swap(report[i], report[i + 1]);
				IsSwapped = true;
			}
		}
	}
	std::reverse(report.begin(), report.end());
	std::map<Date, std::vector<Expense>> resoltReport;
	resoltReport.insert(std::make_pair(date, report));
	return resoltReport;
}

std::map<Date, std::vector<Expense>> ReportGenerator::generateWeekReport(Date date, std::vector<Account*>& accounts) {
	std::vector<Expense> report;
	int count = report.size();
	for (int i = 0; i < accounts.size(); i++) {
		for (int j = 0; j < accounts[i]->getAllExpenses().size(); j++) {
			if ((accounts[i]->getAllExpenses()[j].GetExpenseDate() > date - 8) || (accounts[i]->getAllExpenses()[j].GetExpenseDate() < date)) {
				report.push_back(accounts[i]->getAllExpenses()[j]);
			}
		}
	}
	while (count--) {
		bool IsSwapped = false;
		for (int i = 0; i < count; i++) {
			if (report[i] > report[i + 1]) {
				std::swap(report[i], report[i + 1]);
				IsSwapped = true;
			}
		}
	}
	std::reverse(report.begin(), report.end());
	std::map<Date, std::vector<Expense>> resoltReport;
	resoltReport.insert(std::make_pair(date, report));
	return resoltReport;
}

std::map<Date, std::vector<Expense>> ReportGenerator::generateMonthReport(Date date, std::vector<Account*>& accounts) {
	std::vector<Expense> report;
	int count = report.size();
	for (int i = 0; i < accounts.size(); i++) {
		for (int j = 0; j < accounts[i]->getAllExpenses().size(); j++) {
			if (accounts[i]->getAllExpenses()[j].GetExpenseDate().GetMonth() == date.GetMonth() &&
				accounts[i]->getAllExpenses()[j].GetExpenseDate().GetYear() == date.GetYear()) {
				report.push_back(accounts[i]->getAllExpenses()[j]);
			}
		}
	}
	while (count--) {
		bool IsSwapped = false;
		for (int i = 0; i < count; i++) {
			if (report[i] > report[i + 1]) {
				std::swap(report[i], report[i + 1]);
				IsSwapped = true;
			}
		}
	}
	std::reverse(report.begin(), report.end());
	std::map<Date, std::vector<Expense>> resoltReport;
	resoltReport.insert(std::make_pair(date, report));
	return resoltReport;
}