#include <iostream>
#include "MyString.h"

int MyString::count = 0;

int main() {
	MyString str1("Hello world!");
	str1.Print(); // Hello world!
	std::cout << str1.MyStrLen() << std::endl; // 12
	MyString::ShowNumberOfObjects(); // 1 object

	str1.Input(); // Enter string -> What if I write something like this?
	str1.Print(); // What if I write something like this?
	std::cout << str1.MyStrLen() << std::endl; // 36

	MyString str2;
	str1.MyStrcpy(str2);
	str2.Print(); // What if I write something like this?
	MyString::ShowNumberOfObjects(); // 2 objects

	std::cout << str1.MyStrStr("methi") << std::endl; // 1
	std::cout << str1.MyStrStr("fefew") << std::endl; // 0

	std::cout << str1.MyChr('I') << std::endl; // 8

	MyString str3(" Ok, all tests is passed :)");
	str1.MyStrCat(str3);
	str1.Print(); // What if I write something like this? Ok, all tests is passed :)

	str1.MyDelChr('i');
	str1.Print(); // What f I wrte somethng lke ths? Ok, all tests s passed :)

	MyString str4;
	str1.MyStrcpy(str4);
	std::cout << str1.MyStrCmp(str2) << std::endl; // -1
	std::cout << str2.MyStrCmp(str1) << std::endl; // 1
	std::cout << str1.MyStrCmp(str4) << std::endl; // 0
	MyString::ShowNumberOfObjects(); // 4 objects
}