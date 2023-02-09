#include <iostream>
#include "Stack.h"
#include "List.h"
using namespace std;

void main() {
	srand(time(NULL));

	Stack ST(15);
	char c;

	while (!ST.IsFull()) {
		c = rand() % 65 + 65;
		ST.Push(c);
	}

	for (int i = 0; i < 4; i++) cout << ST.Pop() << " ";

	cout << endl;
	cout << ST.GetCount() << endl << endl;

	List l;
	l.Add('a');
	l.Add('b');
	l.Add('c');
	l.Add('d');
	l.Print(); // a b c d

	l.AddByIndex('e', 2);
	l.Print(); // a e b c d

	l.DelByIndex(5);
	l.Print(); // a e b c

	cout << l.Search('b') << endl; // 3
}