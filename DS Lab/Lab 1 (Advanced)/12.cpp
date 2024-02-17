#include <iostream>
using namespace std;
void printSubstrings(string str, int start, int end) {
    if (start == str.length())
        return;
    for (int len = 1; len <= end - start + 1; ++len) {
        cout << str.substr(start, len) << " ";
    }
  printSubstrings(str, start + 1, end);
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    cout << "All substrings of the given string are: " << endl;
    printSubstrings(str, 0, str.length() - 1);

    return 0;
}