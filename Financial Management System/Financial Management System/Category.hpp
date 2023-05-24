#pragma once
#include <iostream>
#include <vector>
#include <string>

class Category {
private:
	std::string CategoryName;
	double CategoryCashback;

public:
	Category();
	Category(std::string Name, double CategoryCashback);

	std::string GetCategoryName() const;
	double GetCategoryCashback() const;

	std::string toString();

	bool operator == (const Category& c) const;
	bool operator != (const Category& c) const;
};

std::ostream& operator << (std::ostream& o, const Category& c);
std::istream& operator >> (std::istream& i, Category& c);