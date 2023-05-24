#include "Report.hpp"

Report::Report(std::map<Date, std::vector<Expense>> report): report(report) {}

void Report::ShowDayReport(ReportGenerator rp, Date date, std::vector<Account*>& accounts) {
	report = rp.generateDayReport(date, accounts);
	for (auto el : report) {
		for (int i = 0; i < el.second.size(); i++) {
			std::cout << "Day report:" << std::endl
				<< "Date: " << el.first << std::endl
				<< "Info: " << std::endl
				<< el.second[i] << std::endl;
		}
	}
}

void Report::ShowWeekReport(ReportGenerator rp, Date date, std::vector<Account*>& accounts) {
	report = rp.generateWeekReport(date, accounts);
	for (auto el : report) {
		for (int i = 0; i < el.second.size(); i++) {
			std::cout << "Day report:" << std::endl
				<< "Date: " << el.first << std::endl
				<< "Info: " << std::endl
				<< el.second[i] << std::endl;
		}
	}
}

void Report::ShowMonthReport(ReportGenerator rp, Date date, std::vector<Account*>& accounts) {
	report = rp.generateMonthReport(date, accounts);
	for (auto el : report) {
		for (int i = 0; i < el.second.size(); i++) {
			std::cout << "Day report:" << std::endl
				<< "Date: " << el.first << std::endl
				<< "Info: " << std::endl
				<< el.second[i] << std::endl;
		}
	}
}

void Report::AddToFileDayReport(ReportGenerator rp, Date date, std::vector<Account*>& accounts) {
	report = rp.generateDayReport(date, accounts);
	std::string result;
	for (auto& pair : report) {
		result += pair.first.toString() + ":\n";
		for (auto& expense : pair.second) result += " " + expense.toString() + "\n";
		result += "\n";
	}
	char* charArray = new char[result.length() + 1];
	strcpy_s(charArray, result.length() + 1, result.c_str());
	std::ofstream ReportDB("DayReportDB.dat", std::ios::binary);
	ReportDB.write(charArray, report.size() * sizeof(report));
	ReportDB.close();
}

void Report::AddToFileWeekReport(ReportGenerator rp, Date date, std::vector<Account*>& accounts) {
	report = rp.generateWeekReport(date, accounts);
	std::string result;
	for (auto& pair : report) {
		result += pair.first.toString() + ":\n";
		for (auto& expense : pair.second) result += " " + expense.toString() + "\n";
		result += "\n";
	}
	char* charArray = new char[result.length() + 1];
	strcpy_s(charArray, result.length() + 1, result.c_str());
	std::ofstream ReportDB("WeekReportDB.dat", std::ios::binary);
	ReportDB.write(charArray, report.size() * sizeof(report));
	ReportDB.close();
}

void Report::AddToFileMonthReport(ReportGenerator rp, Date date, std::vector<Account*>& accounts) {
	report = rp.generateMonthReport(date, accounts);
	std::string result;
	for (auto& pair : report) {
		result += pair.first.toString() + ":\n";
		for (auto& expense : pair.second) result += " " + expense.toString() + "\n";
		result += "\n";
	}
	char* charArray = new char[result.length() + 1];
	strcpy_s(charArray, result.length() + 1, result.c_str());
	std::ofstream ReportDB("MonthReportDB.dat", std::ios::binary);
	ReportDB.write(charArray, report.size() * sizeof(report));
	ReportDB.close();
}

void Report::ShowWeekRatingByPrice(ReportGenerator rp, Date date, std::vector<Account*>& accounts) {
	report = rp.generateWeekReport(date, accounts);
	int count = 0;
	for (auto el : report) {
		for (int i = 0; i < 3; i++) {
			std::cout << "Day report:" << std::endl
				<< "Date: " << el.first << std::endl
				<< "Info: " << std::endl
				<< el.second[i] << std::endl;
		}
	}
}

void Report::ShowMonthRatingByPrice(ReportGenerator rp, Date date, std::vector<Account*>& accounts) {
	report = rp.generateWeekReport(date, accounts);
	int count = 0;
	for (auto el : report) {
		for (int i = 0; i < 3; i++) {
			std::cout << "Day report:" << std::endl
				<< "Date: " << el.first << std::endl
				<< "Info: " << std::endl
				<< el.second[i] << std::endl;
		}
	}
}

void Report::ShowWeekRatingByCategory(ReportGenerator rp, Date date, std::vector<Account*>& accounts) {
	std::vector<Category> categoryVect;
	std::vector<int> categoryVectCount;
	report = rp.generateWeekReport(date, accounts);
	for (auto el : report) {
		for (auto elem : el.second) {
			Category tmp = elem.GetExpenseCategory();
			for (int i = 0; i < categoryVect.size(); i++) if (categoryVect[i] != tmp) categoryVect.push_back(tmp);
		}
	}
	for (int i = 0; i < categoryVect.size(); i++) {
		int count = 0;
		Category tmp = categoryVect[i];
		for (auto el : report) {
			for (auto elem : el.second) {
				Category tmp = elem.GetExpenseCategory();
				for (int i = 0; i < categoryVect.size(); i++) if (categoryVect[i] == tmp) count++;
			}
		}
		categoryVectCount.push_back(count);
	}
	std::multimap<int, Category> CategoryMap;
	for (int i = 0; i < categoryVect.size(); i++) CategoryMap.insert({ categoryVectCount[i], categoryVect[i] });
	int num = 1;
	std::cout << "Week rating by category: " << std::endl;
	for (auto el : CategoryMap) {
		std::cout << " " << num << ". " << el.second << " (" << el.first << " Expenses)" << std::endl;
		num++;
		if (num == 3) break;
	}
}

void Report::ShowMonthRatingByCategory(ReportGenerator rp, Date date, std::vector<Account*>& accounts) {
	std::vector<Category> categoryVect;
	std::vector<int> categoryVectCount;
	report = rp.generateMonthReport(date, accounts);
	for (auto el : report) {
		for (auto elem : el.second) {
			Category tmp = elem.GetExpenseCategory();
			for (int i = 0; i < categoryVect.size(); i++) if (categoryVect[i] != tmp) categoryVect.push_back(tmp);
		}
	}
	for (int i = 0; i < categoryVect.size(); i++) {
		int count = 0;
		Category tmp = categoryVect[i];
		for (auto el : report) {
			for (auto elem : el.second) {
				Category tmp = elem.GetExpenseCategory();
				for (int i = 0; i < categoryVect.size(); i++) if (categoryVect[i] == tmp) count++;
			}
		}
		categoryVectCount.push_back(count);
	}
	std::multimap<int, Category> CategoryMap;
	for (int i = 0; i < categoryVect.size(); i++) CategoryMap.insert({categoryVectCount[i], categoryVect[i]});
	int num = 1;
	std::cout << "Week rating by category: " << std::endl;
	for (auto el : CategoryMap) {
		std::cout << " " << num << ". " << el.second << " (" << el.first << " Expenses)" << std::endl;
		num++;
		if (num == 3) break;
	}
}

void Report::AddToFileWeekRatingByPrice(ReportGenerator rp, Date date, std::vector<Account*>& accounts) {
	report = rp.generateWeekReport(date, accounts);
	std::string result;
	for (auto el : report) {
		result += el.first.toString() + ":\n";
		for (int i = 0; i < 3; i++) result += " " + el.second[i].toString() + "\n";
		result += "\n";
	}
	char* charArray = new char[result.length() + 1];
	strcpy_s(charArray, result.length() + 1, result.c_str());
	std::ofstream RatingDB("WeekRatingDB.dat", std::ios::binary);
	RatingDB.write(charArray, report.size() * sizeof(report));
	RatingDB.close();
}

void Report::AddToFileMonthRatingByPrice(ReportGenerator rp, Date date, std::vector<Account*>& accounts) {
	report = rp.generateMonthReport(date, accounts);
	std::string result;
	for (auto el : report) {
		result += el.first.toString() + ":\n";
		for (int i = 0; i < 3; i++) result += " " + el.second[i].toString() + "\n";
		result += "\n";
	}
	char* charArray = new char[result.length() + 1];
	strcpy_s(charArray, result.length() + 1, result.c_str());
	std::ofstream RatingDB("MonthRatingDB.dat", std::ios::binary);
	RatingDB.write(charArray, report.size() * sizeof(report));
	RatingDB.close();
}

void Report::AddToFileWeekRatingByCategory(ReportGenerator rp, Date date, std::vector<Account*>& accounts) {
	std::vector<Category> categoryVect;
	std::vector<int> categoryVectCount;
	report = rp.generateWeekReport(date, accounts);
	for (auto el : report) {
		for (auto elem : el.second) {
			Category tmp = elem.GetExpenseCategory();
			for (int i = 0; i < categoryVect.size(); i++) if (categoryVect[i] != tmp) categoryVect.push_back(tmp);
		}
	}
	for (int i = 0; i < categoryVect.size(); i++) {
		int count = 0;
		Category tmp = categoryVect[i];
		for (auto el : report) {
			for (auto elem : el.second) {
				Category tmp = elem.GetExpenseCategory();
				for (int i = 0; i < categoryVect.size(); i++) if (categoryVect[i] == tmp) count++;
			}
		}
		categoryVectCount.push_back(count);
	}
	std::multimap<int, Category> CategoryMap;
	for (int i = 0; i < categoryVect.size(); i++) CategoryMap.insert({ categoryVectCount[i], categoryVect[i] });

	std::string result;
	for (auto el : CategoryMap) {
		result += std::to_string(el.first) + ":\n";
		for (int i = 0; i < 3; i++) result += " " + el.second.toString() + "\n";
		result += "\n";
	}
	char* charArray = new char[result.length() + 1];
	strcpy_s(charArray, result.length() + 1, result.c_str());
	std::ofstream RatingDB("WeekRatingByCategoryDB.dat", std::ios::binary);
	RatingDB.write(charArray, report.size() * sizeof(report));
	RatingDB.close();
}

void Report::AddToFileMonthRatingByCategory(ReportGenerator rp, Date date, std::vector<Account*>& accounts) {
	std::vector<Category> categoryVect;
	std::vector<int> categoryVectCount;
	report = rp.generateMonthReport(date, accounts);
	for (auto el : report) {
		for (auto elem : el.second) {
			Category tmp = elem.GetExpenseCategory();
			for (int i = 0; i < categoryVect.size(); i++) if (categoryVect[i] != tmp) categoryVect.push_back(tmp);
		}
	}
	for (int i = 0; i < categoryVect.size(); i++) {
		int count = 0;
		Category tmp = categoryVect[i];
		for (auto el : report) {
			for (auto elem : el.second) {
				Category tmp = elem.GetExpenseCategory();
				for (int i = 0; i < categoryVect.size(); i++) if (categoryVect[i] == tmp) count++;
			}
		}
		categoryVectCount.push_back(count);
	}
	std::multimap<int, Category> CategoryMap;
	for (int i = 0; i < categoryVect.size(); i++) CategoryMap.insert({ categoryVectCount[i], categoryVect[i] });

	std::string result;
	for (auto el : CategoryMap) {
		result += std::to_string(el.first) + ":\n";
		for (int i = 0; i < 3; i++) result += " " + el.second.toString() + "\n";
		result += "\n";
	}
	char* charArray = new char[result.length() + 1];
	strcpy_s(charArray, result.length() + 1, result.c_str());
	std::ofstream RatingDB("MonthRatingByCategoryDB.dat", std::ios::binary);
	RatingDB.write(charArray, report.size() * sizeof(report));
	RatingDB.close();
}