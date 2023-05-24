#include "Category.hpp"

Category::Category(): CategoryName("None"), CategoryCashback(0.0){}

Category::Category(std::string CategoryName, double CategoryCashback): CategoryName(CategoryName), CategoryCashback(CategoryCashback){}

std::string Category::GetCategoryName() const { return CategoryName; }

double Category::GetCategoryCashback() const { return CategoryCashback; }

std::string Category::toString() { return "Category name: " + CategoryName + "\nCategory cashback: " + std::to_string(CategoryCashback); }

bool Category::operator == (const Category& c) const { return CategoryName == c.GetCategoryName(); }

bool Category::operator!=(const Category& c) const { return CategoryName != c.GetCategoryName(); }

std::ostream& operator<<(std::ostream& o, const Category& c) {
	o << "Category: " << c.GetCategoryName() << std::endl << "Cashback: " << c.GetCategoryCashback();
	return o;
}

std::istream& operator >> (std::istream& i, Category& c) {
	std::string CategoryName;
	double CategoryCashback;

	std::cout << "Category name: ";
	i >> CategoryName;
	std::cout << "Category cashback: ";
	i >> CategoryCashback;

	return i;
}