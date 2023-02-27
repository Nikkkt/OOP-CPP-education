#include <iostream>
#include <conio.h>
#include "Stack.h"
#include "List.h"
#include "Tree.h"
#include "Functions.h"
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
	l.Print(2); // e
	l.PrintHead(); // a

	l.AddToHead('1');
	l.Print();

	cout << l.Search('b') << endl << endl; // 4

    cout << "//////////////////////////////////////////" << endl;

    Tree tree;

    bool exit = false;

    while (true) {
        PrintMenu();
        int choice = _getch();

        switch (choice) {
        case '1':
            Insert(tree);
            break;
        case '2':
            Remove(tree);
            break;
        case '3':
            Print(tree);
            break;
        case '4':
            Search(tree);
            break;
        case '5':
            exit = true;
            break;
        }

        if (exit) break;
    }
}