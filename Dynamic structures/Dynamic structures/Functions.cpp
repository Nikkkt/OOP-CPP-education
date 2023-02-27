#include <conio.h>
#include <iostream>
#include "Functions.h"
using namespace std;

void Insert(Tree& tree) {
    system("cls");
    cout << "Enter a quantity of elements to add: ";

    unsigned int count = 0U;
    cin >> count;

    for (unsigned int i = 0U; i < count; ++i) {
        Elem* temp = new Elem;

        cout << endl << "Enter a fullname " << i + 1 << endl;
        cin >> temp->GetFullName();

        cout << endl << "Enter an average " << i + 1 << endl;
        cin >> temp->average;

        tree.Insert(temp);
    }
}

void Print(const Tree& tree) {
    system("cls");
    tree.Print(tree.GetRoot());
    _getch();
}

void PrintMenu() {
    char menu[] = "1. Insert elem\n2. Remove elem\n3. Print elem\n4. Search elem\n5. Exit\n";
    system("cls");
    cout << menu;
}

void Remove(Tree& tree) {
    system("cls");
    cout << "Enter an fullname to remove:" << endl;

    char buffer[15];
    cin >> buffer;

    Elem* node = tree.Search(tree.GetRoot(), buffer);

    tree.Remove(node);
}

void Search(const Tree& tree) {
    system("cls");
    cout << "Enter a fullname to search:" << endl;

    char buffer[15];
    cin >> buffer;

    Elem* node = tree.Search(tree.GetRoot(), buffer);

    if (node != nullptr) cout << node->GetAverage();
    else cout << "Name not found" << endl;

    _getch();
}