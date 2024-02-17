#include <iostream>
using namespace std;

int main() {
    const int MAX_STRINGS = 5;
    char* strings[MAX_STRINGS];
    cout << "Enter up to " << MAX_STRINGS << " strings" << endl;
    for (int i = 0; i < MAX_STRINGS; ++i) {
        strings[i] = new char[100];
        cin.getline(strings[i], 100);
    }

    cout << "\nStrings in reverse order:" << endl;
    for (int i = MAX_STRINGS - 1; i >= 0; --i) {
        cout << strings[i] << endl;
    }

    for (int i = 0; i < MAX_STRINGS; ++i) {
        delete[] strings[i];
    }

    return 0;
}