#include "Expense.hpp"

Expense::Expense() : ExpenseAmount(0), ExpenseCategory(Category()), ExpenseDate(Date()), ExpenseTime(Time()) {}

Expense::Expense(double ExpenseAmount, Category ExpenseCategory, Date ExpenseDate, Time ExpenseTime) : 
	ExpenseAmount(ExpenseAmount), ExpenseCategory(ExpenseCategory), ExpenseDate(ExpenseDate), ExpenseTime(ExpenseTime) {}

Expense::Expense(double ExpenseAmount, std::string ExpenseCategoryName, double ExpenseCategoryCashback, unsigned short day, unsigned short month, unsigned short year, unsigned short seconds, unsigned short minutes, unsigned short hours) :
	ExpenseAmount(ExpenseAmount), ExpenseCategory(Category(ExpenseCategoryName, ExpenseCategoryCashback)), ExpenseDate(Date(day, month, year)), ExpenseTime(Time(seconds, minutes, hours)) {}

double Expense::GetExpenseAmount() const { return ExpenseAmount; }
Category Expense::GetExpenseCategory() const { return ExpenseCategory; }
Date Expense::GetExpenseDate() const { return ExpenseDate; }
Time Expense::GetExpenseTime() const { return ExpenseTime; }

std::string Expense::toString() { return "Expense: \nAmount: " + std::to_string(ExpenseAmount) + "\nCategory: " + ExpenseCategory.toString() + "\nDate: " + ExpenseDate.toString() + "\nTime: " + ExpenseTime.toString(); }

void Expense::SetExpenseAmount(double ExpenseAmount) { this->ExpenseAmount = ExpenseAmount; }
void Expense::SetExpenseCategory(Category ExpenseCategory) { this->ExpenseCategory = ExpenseCategory; }
void Expense::SetExpenseDate(Date ExpenseDate) { this->ExpenseDate = ExpenseDate; }
void Expense::SetExpenseTime(Time ExpenseTime) { this->ExpenseTime = ExpenseTime; }

bool Expense::operator < (const Expense& e) const { return ExpenseAmount < e.ExpenseAmount; }
bool Expense::operator > (const Expense& e) const { return ExpenseAmount > e.ExpenseAmount; }

std::ostream& operator << (std::ostream& o, const Expense& e) {
	o << "Expense: " << std::endl
		<< "Amount: " << e.ExpenseAmount << std::endl
		<< "Category: " << std::endl << e.ExpenseCategory << std::endl
		<< "Date: " << e.ExpenseDate << std::endl
		<< "Time: " << e.ExpenseTime;
	return o;
}

std::istream& operator >> (std::istream& i, Expense& e) {
	std::cout << "New Expense:" << std::endl << "Amount: ";
	i >> e.ExpenseAmount;
	std::cout << "Category: ";
	i >> e.ExpenseCategory;
	i >> e.ExpenseDate;
	i >> e.ExpenseTime;

	return i;
}