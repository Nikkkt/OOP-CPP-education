#include <iostream>
#include "MyArray.h"
using namespace std;

int main() {
	srand(time(NULL));
	MyArray<int> arr1(5);
	MyArray<int> arr2(4);

	arr1.Input();
	arr2.Input();

	arr1.Print();
	arr2.Print();

	cout << arr1[-2] << endl;

	MyArray<int> arr3;
	arr3 = arr1 + arr2;
	arr3.Print();
	cout << arr3.GetSize() << endl; // 9

	arr3.Add(5);
	arr3.Print();
	cout << arr3.GetSize() << endl; // 10

	arr3.Del();
	arr3.Print();
	cout << arr3.GetSize() << endl; // 9
}