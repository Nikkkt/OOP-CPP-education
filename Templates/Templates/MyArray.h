#pragma once
#include <iostream>
using namespace std;

template<class T>
class MyArray {
    T* arr;
    int count;

public:
    MyArray();
    MyArray(int size);
    MyArray(const MyArray<T>& ar);

    void Input();
    void Print();

    int GetSize();
    bool IsEmpty();

    ~MyArray();

    MyArray<T>& operator = (const MyArray<T>& orig);

    MyArray<T> operator + (int b);
    MyArray<T> operator - (int b);

    MyArray<T> operator ++ (int);
    MyArray<T> operator ++ ();

    MyArray<T> operator -- (int);
    MyArray<T> operator -- ();

    T operator [] (int index);

    MyArray<T> operator + (const MyArray<T>& b);
};

template<class T>
MyArray<T>::MyArray(): count(0) { arr = nullptr; }

template<class T>
MyArray<T>::MyArray(int size): count(size) { arr = new T[count]; }

template<class T>
MyArray<T>::MyArray(const MyArray<T>& obj): count(obj.count) {
    arr = new T[count];
    for (int i = 0; i < count; i++) arr[i] = obj.arr[i];
}

template<class T>
void MyArray<T>::Input() { for (int i = 0; i < count; i++) arr[i] = rand() % 100 * 2.5; }

template<class T>
void MyArray<T>::Print() {
    for (int i = 0; i < count; i++) cout << arr[i] << "\t";
    cout << endl;
}

template<class T>
int MyArray<T>::GetSize() { return count; }

template<class T>
bool MyArray<T>::IsEmpty() { return count == 0; }

template<class T>
MyArray<T>::~MyArray() { delete[] arr; }

template<class T>
MyArray<T>& MyArray<T>::operator = (const MyArray<T>& orig) {
    if (&orig != this) {
        count = orig.count;
        if (arr != nullptr) delete[] arr;
        arr = new T[count];
        for (int i = 0; i < count; i++) arr[i] = orig.arr[i];
    }
    return *this;
}

template<class T>
MyArray<T> MyArray<T>::operator + (int b) {
    int tempCount = count;
    MyArray<T> tmp(tempCount);

    for (int i = 0; i < count; i++) tmp.arr[i] = arr[i];
    count += b;
    delete[] arr;

    arr = new T[count];
    for (int i = 0; i < tmp.count; i++) arr[i] = tmp.arr[i];
    for (int i = tmp.count; i < count; i++) arr[i] = 0;

    tmp = *this;
    return tmp;
}

template<class T>
MyArray<T> MyArray<T>::operator - (int b) {
    int tempCount = count;
    MyArray<T> tmp(tempCount);

    for (int i = 0; i < count; i++) tmp.arr[i] = arr[i];
    count -= b;
    delete[] arr;

    arr = new T[count];
    for (int i = 0; i < count; i++) arr[i] = tmp.arr[i];

    tmp = *this;
    return tmp;
}

template<class T>
MyArray<T> MyArray<T>::operator ++ (int) {
    int tempCount = count;
    MyArray<T> tmp(tempCount);

    for (int i = 0; i < count; i++) tmp.arr[i] = arr[i];
    count += 1;

    delete[] arr;
    arr = new T[count];

    for (int i = 0; i < tmp.count; i++) arr[i] = tmp.arr[i];
    arr[count - 1] = 0;

    tmp = *this;
    return tmp;
}

template<class T>
MyArray<T> MyArray<T>::operator ++ () {
    int tempCount = count;
    MyArray<T> tmp(tempCount);

    for (int i = 0; i < count; i++) tmp.arr[i] = arr[i];
    count += 1;

    delete[] arr;
    arr = new T[count];

    for (int i = 0; i < tmp.count; i++) arr[i] = tmp.arr[i];
    arr[count - 1] = 0;

    return *this;
}

template<class T>
MyArray<T> MyArray<T>::operator -- (int) {
    int tempCount = count;
    MyArray<T> tmp(tempCount);

    for (int i = 0; i < count; i++) tmp.arr[i] = arr[i];
    count -= 1;

    delete[] arr;
    arr = new T[count];

    for (int i = 0; i < count; i++) arr[i] = tmp.arr[i];

    tmp = *this;
    return tmp;
}

template<class T>
MyArray<T> MyArray<T>::operator -- () {
    int tempCount = count;
    MyArray<T> tmp(tempCount);

    for (int i = 0; i < count; i++) tmp.arr[i] = arr[i];
    count -= 1;

    delete[] arr;
    arr = new T[count];

    for (int i = 0; i < count; i++) arr[i] = tmp.arr[i];

    return *this;
}

template<class T>
T MyArray<T>::operator [] (int index) {
    if (index < 0) return arr[count + index];
    else if (index >= count || index <= -count) throw "Out of array";
    return arr[index];
}

template<class T>
MyArray<T> MyArray<T>::operator + (const MyArray<T>& b) {
    int tempCount = count;
    MyArray<T> tmp(tempCount);

    for (int i = 0; i < count; i++) tmp.arr[i] = arr[i];
    count += b.count;

    delete[] arr;
    arr = new T[count];
    
    for (int i = 0; i < tmp.count; i++) arr[i] = tmp.arr[i];
    for (int i = tmp.count, j = 0; i < count; i++, j++) arr[i] = b.arr[j];

    tmp = *this;
    return tmp;
}