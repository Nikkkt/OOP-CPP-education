#include "ReportGenerator.h"
#include <algorithm>

std::vector<Expense> ReportGenerator::generateDayReport(Date date, std::vector<Account*>& accounts) {
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
	return report;
}

std::vector<Expense> ReportGenerator::generateWeekReport(Date date, std::vector<Account*>& accounts) {
	std::vector<Expense> report;
	int count = report.size();
	for (int i = 0; i < accounts.size(); i++) {
		for (int j = 0; j < accounts[i]->getAllExpenses().size(); j++) {
			if () {
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
	return report;
}

std::vector<Expense> ReportGenerator::generateMonthReport(Date date, std::vector<Account*>& accounts) {
	std::vector<Expense> report;
	int count = report.size();
	for (int i = 0; i < accounts.size(); i++) {
		for (int j = 0; j < accounts[i]->getAllExpenses().size(); j++) {
			if (accounts[i]->getAllExpenses()[j].GetExpenseDate().daysInMonth() == date.GetMonth() &&
				accounts[i]->getAllExpenses()[j].GetExpenseDate().daysInYear() == date.GetYear()) {
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
	return report;
}