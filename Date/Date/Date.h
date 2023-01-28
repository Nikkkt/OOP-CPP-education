#pragma once
class Date {
private:
	int day;
	int month;
	int year;

	Date(int day);
	Date(int day, int month);

public:
	Date();
	Date(int day, int month, int year);

	void Print();
	void Init();

	int GetDay() const;
	int GetMonth() const;
	int GetYear() const;

	void SetDay(int day);
	void SetMonth(int month);
	void SetYear(int year);

	Date& operator ++ ();
	Date& operator -- ();
	Date operator ++ (int);
	Date operator -- (int);

	Date operator + (int b);
	Date operator - (int b);
	Date operator - (Date b);

	Date& operator += (int b);
	Date& operator -= (int b);

	bool operator == (const Date& b);
	bool operator != (const Date& b);

	bool operator < (const Date& b);
	bool operator <= (const Date& b);

	bool operator > (const Date& b);
	bool operator >= (const Date& b);

	friend std::ostream& operator << (std::ostream& o, const Date& d);
	friend std::istream& operator >> (std::istream& i, Date& d);
};