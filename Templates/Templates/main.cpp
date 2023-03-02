#include "MyArray.h"
#include "Point.h"

std::string TextEditing(std::string text);

int main() {
    srand(time(0));

    MyArray<int> arrInt(5);
    arrInt.Input();
    std::cout << "Arr1: ";
    arrInt.PrintDev();

    MyArray<int> arrInt2(3);
    arrInt2.Input();
    std::cout << "Arr2: ";
    arrInt2.PrintDev();

    //IsEmpty
    std::cout << std::endl << std::boolalpha << "Arr1: " << arrInt.IsEmpty() << std::endl << "Arr2: " << arrInt2.IsEmpty() << std::endl;

    //SetSize
    arrInt.SetSize(3);
    std::cout << "Arr1: ";
    arrInt.PrintDev();

    arrInt2.SetSize(4);
    std::cout << "Arr2: ";
    arrInt2.PrintDev();

    //GetAt
    std::cout << std::endl << "Arr1: " << arrInt.GetAt(2) << std::endl << "Arr2: " << arrInt2.GetAt(2) << std::endl;

    //SetAt
    std::cout << std::endl <<"Arr1: ";
    arrInt.SetAt(6, 2);
    arrInt.PrintDev();

    std::cout << "Arr2: ";
    arrInt2.SetAt(14, 1);
    arrInt2.PrintDev();

    //Add
    std::cout << std::endl << "Arr1: ";
    arrInt.Add(54);
    arrInt.PrintDev();

    std::cout << "Arr2: ";
    arrInt2.Add(45);
    arrInt2.PrintDev();

    //SetSize
    arrInt.SetSize(8, 4);
    std::cout << "Arr1: ";
    arrInt.PrintDev();

    arrInt2.SetSize(5, 3);
    std::cout << "Arr2: ";
    arrInt2.PrintDev();

    //Add
    arrInt.Add(20);
    std::cout << std::endl << "Arr1: ";
    arrInt.PrintDev();

    arrInt2.Add(29);
    std::cout << "Arr2: ";
    arrInt2.PrintDev();

    //Sum
    std::cout << std::endl << "Sum of Arr1: " << arrInt.Sum() << std::endl;
    std::cout << "Sum of Arr2: " << arrInt2.Sum() << std::endl;

    //Append
    arrInt.Append(arrInt2);
    std::cout << std::endl << "Arr: ";
    arrInt.PrintDev();

    //InsertAt
    arrInt.InsertAt(25, 3);
    std::cout << std::endl << "Arr: ";
    arrInt.PrintDev();

    const int SIZE = 4;
    int* ar = new int[SIZE];
    for (int i = 0; i < SIZE; i++) ar[i] = rand() % 20;

    arrInt.InsertAt(ar, SIZE, 3);
    std::cout << std::endl << "Arr: ";
    arrInt.PrintDev();

    //RemoteAt
    arrInt.RemoveAt(2);
    std::cout << std::endl << "Arr: ";
    arrInt.PrintDev();

    arrInt.RemoveAt(2, 5);
    std::cout << std::endl << "Arr: ";
    arrInt.PrintDev();

    //FreeExtra
    arrInt.FreeExtra();
    std::cout << std::endl << "Arr: ";
    arrInt.PrintDev();

    //RemoveAll
    arrInt.RemoveAll();
    std::cout << std::endl << "Arr: ";
    arrInt.PrintDev();

    delete[] ar;

    std::cout << std::endl << std::endl << std::endl;

    /////////////////////// Sum ///////////////////////

    MyArray<double> arrDouble(7);
    MyArray<char> arrChar(6);

    MyArray<Point<int>> arrPointInt(5);
    MyArray<Point<double>> arrPointDouble(4);
    MyArray<Point<char>> arrPointChar(3);
    MyArray<Point<Point<int>>> arrPointPointInt(2);

    arrDouble.Input(); //to init array
    for (int i = 0; i < arrDouble.GetSize(); i++) arrDouble[i] /= 10;
    std::cout << "Double array: ";
    arrDouble.PrintDev();

    arrChar.Input(); //to init array
    std::cout << "Char array: ";
    arrChar.PrintDev();

    arrPointInt.Input(); //to init array
    std::cout << "Int-Point array: ";
    arrPointInt.PrintDev();

    arrPointDouble.Input(); //to init array
    std::cout << "Double-Point array: ";
    arrPointDouble.PrintDev();

    arrPointChar.Input(); //to init array
    std::cout << "Char-Point array: ";
    arrPointChar.PrintDev();

    for (int i = 0; i < arrPointPointInt.GetSize(); i++) {
        arrPointPointInt[i] = Point<Point<int>>(
            Point<int>(rand() % 100, rand() % 100, rand() % 100),
            Point<int>(rand() % 100, rand() % 100, rand() % 100),
            Point<int>(rand() % 100, rand() % 100, rand() % 100));
    }
    std::cout << "Int-Point-Point array: ";
    arrPointPointInt.PrintDev();
    std::cout << std::endl;

    std::cout << "Double array sum: " << arrDouble.Sum() << std::endl;
    std::cout << "Char array sum: " << arrChar.Sum() << " (" << (int)arrChar.Sum() << ")" << std::endl;
    std::cout << "Int-Point array sum: " << arrPointInt.Sum() << std::endl;
    std::cout << "Double-Point array sum: " << arrPointDouble.Sum() << std::endl;
    std::cout << "Char-Point array sum: " << arrPointChar.Sum() << std::endl;
    std::cout << "Int-Point-Point array sum: " << arrPointPointInt.Sum() << std::endl << std::endl;

    MyArray<Point<int>> testArr{Point<int>(1, 2, 3), Point<int>(4, 5, 6), Point<int>(7, 8, 9)};
    testArr.PrintDev(); // (1, 2, 3) (4, 5, 6) (7, 8, 9) |
    std::cout << std::endl << std::endl;

    std::string text = "    This     is   a   text    ";
    std::string editingText = TextEditing(text);
    std::cout << "\"" << text << "\"" << std::endl << "\"" << editingText << "\"" << std::endl;
    //"    This     is   a   text    "
    //"    This is a text    "
}

std::string TextEditing(std::string text) {
    std::string editingText;
    bool spaceEncountered = false;
    int j = 0, count = 0;

    while (text[j] == ' ') {
        count++;
        j++;
    }
    for (int i = 0; i < count - 1; i++) editingText += ' ';

    for (char symbol : text) {
        if (symbol == ' ') spaceEncountered = true;
        else {
            if (spaceEncountered) {
                editingText += ' ';
                spaceEncountered = false;
            }
            editingText += symbol;
        }
    }
    if (spaceEncountered) editingText += ' ';

    j = text.size() - 1;
    count = 0;

    while (text[j] == ' ') {
        count++;
        j--;
    }
    for (int i = 0; i < count - 1; i++) editingText.push_back(' ');

    return editingText;
}