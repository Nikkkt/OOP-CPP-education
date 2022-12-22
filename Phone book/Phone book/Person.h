#pragma once
class Person {
private:
	char* FullName;
	char* HomePhone;
	char* WorkPhone;
	char* MobilePhone;
	char* AdditionalInfo;

public:
	Person();
	Person(const char* FullName, const char* HomePhone, const char* WorkPhone, const char* MobilePhone, const char* AdditionalInfo);
	~Person();

	void Init();
	void Print();
};