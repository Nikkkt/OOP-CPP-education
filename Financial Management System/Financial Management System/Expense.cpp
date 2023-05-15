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

void Expense::SetExpenseAmount(double ExpenseAmount) { this->ExpenseAmount = ExpenseAmount; }
void Expense::SetExpenseCategory(Category ExpenseCategory) { this->ExpenseCategory = ExpenseCategory; }
void Expense::SetExpenseDate(Date ExpenseDate) { this->ExpenseDate = ExpenseDate; }
void Expense::SetExpenseTime(Time ExpenseTime) { this->ExpenseTime = ExpenseTime; }

bool Expense::operator < (const Expense& e) const { return ExpenseAmount < e.ExpenseAmount; }
bool Expense::operator > (const Expense& e) const { return ExpenseAmount > e.ExpenseAmount; }

std::ostream& operator << (std::ostream& o, const Expense& e) {
	o << "Expense: " << std::endl
		<< "Amount: " << e.GetExpenseAmount() << std::endl
		<< "Category: " << e.GetExpenseCategory() << std::endl
		<< "Date: " << e.GetExpenseDate() << std::endl
		<< "Time: " << e.GetExpenseTime();
	return o;
}

std::istream& operator >> (std::istream& i, Expense& e) {
	double ExpenseAmount;
	Category ExpenseCategory;
	Date ExpenseDate;
	Time ExpenseTime;

	std::cout << "New Expense:" << std::endl << "Amount: ";
	i >> ExpenseAmount;
	std::cout << "Category: ";
	i >> ExpenseCategory;
	i >> ExpenseDate;
	i >> ExpenseTime;

	return i;
}