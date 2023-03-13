#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    // 1
    string str;
    getline(cin, str);
    cout << str << endl;
    replace(str.begin(), str.end(), ' ', '\t');
    cout << str << endl;

    // 2
    string str5;
    getline(cin, str5);
    int count = 0, pos = 0;
    while (true) {
        pos = str5.find("and", pos);
        if (pos != -1) {
            count++;
            pos++;
        }
        else break;
    }
    cout << count << endl;

    // 3
    string str2;
    string chars = "aeyuio";
    getline(cin, str2);
    cout << str2 << endl;
    for (char c : chars) str2.erase(remove(str2.begin(), str2.end(), c), str2.end());
    cout << str2 << endl;

    // 4
    string str3;
    getline(cin, str3);
    int n = 0;
    for (int i = 0; i < str3.size(); i++) if (str3[i] == ' ' && str3[i + 1] != ' ') n++;
    cout << n + 1 << endl;

    // 5
    string str4;
    getline(cin, str4);
    cout << str4 << endl;
    string symbol;
    int pos;
    cout << "Enter a symbol or fragment of a line: ";
    cin >> symbol;
    cout << "Enter a position: ";
    cin >> pos;
    str4.insert(pos, symbol);
    cout << str4 << endl;
}