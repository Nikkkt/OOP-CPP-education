#pragma once
class MyString {
private:
	// Fields
	char* str;
	int length;

	static int count;

public:
	// Constructors, destructor
	MyString();
	MyString(const char* str);
	MyString(const MyString& copyStr);
	~MyString();

	//////////////// METHODS ////////////////

	// Input from keyboard
	void Input();

	// Print to console
	void Print();

	// String copy
	void MyStrcpy(MyString& obj);

	// Search for a substring in a string
	bool MyStrStr(const char* str);

	// Search for a character in a string
	int MyChr(char c);

	// String length
	int MyStrLen();

	// String concatenation
	void MyStrCat(MyString& b);

	// Remove the specified character
	void MyDelChr(char c);

	// String comparison 
	// -1 - the first string is less than the second
	// 1 - the first string is bigger than the second
	// 0 - strings are equal
	int MyStrCmp(MyString& b);

	static void ShowNumberOfObjects();
};