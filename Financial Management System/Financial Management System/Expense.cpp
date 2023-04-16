#include "Expense.hpp"

Expense::Expense() : ExpenseAmount(0), ExpenseCategory("No category"), ExpenseDate(Date()), ExpenseTime(Time()) {}

Expense::Expense(double ExpenseAmount, std::string ExpenseCategory, Date ExpenseDate, Time ExpenseTime) : 
	ExpenseAmount(ExpenseAmount), ExpenseCategory(ExpenseCategory), ExpenseDate(ExpenseDate), ExpenseTime(ExpenseTime) {}

Expense::Expense(double ExpenseAmount, std::string ExpenseCategory, unsigned short day, unsigned short month, unsigned short year, unsigned short seconds, unsigned short minutes, unsigned short hours) :
	ExpenseAmount(ExpenseAmount), ExpenseCategory(ExpenseCategory), ExpenseDate(Date(day, month, year)), ExpenseTime(Time(seconds, minutes, hours)) {}

double Expense::GetExpenseAmount() const { return ExpenseAmount; }

std::string Expense::GetExpenseCategory() const { return ExpenseCategory; }

Date Expense::GetExpenseDate() const { return ExpenseDate; }

Time Expense::GetExpenseTime() const { return ExpenseTime; }

std::ostream& operator << (std::ostream& o, const Expense& e) {
	o << "Expense: " << std::endl
		<< "Amount: " << e.GetExpenseAmount() << std::endl
		<< "Category: " << e.GetExpenseCategory() << std::endl
		<< "Date: " << e.GetExpenseDate() << std::endl
		<< "Time: " << e.GetExpenseTime();
	return o;
}