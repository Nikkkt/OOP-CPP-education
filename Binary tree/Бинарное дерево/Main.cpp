#include <conio.h>
#include <iostream>

#include "Functions.h"
#include "Tree.h"

static int a;

using namespace std;

int main()
{
	cout << a;

    Tree tree;

    bool exit = false;

    for (;;)
	{
		PrintMenu();

		int choice = _getch();

		switch (choice)
		{
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

        if (exit)
        {
            break;
        }
	}

    return 0;
}