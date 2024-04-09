#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isFibonacciSequence(const vector<int>& numbers) {
    int n = numbers.size();
    if (n <= 2) 
        return true;

    for (int i = 2; i < n; ++i) {
        if (numbers[i] != numbers[i - 1] + numbers[i - 2]) {
            return false;
        }
    }
    return true;
}

int main() {
    string input;
    cout << "Enter a string of digits: ";
    cin >> input;

    vector<int> numbers;
    for (char c : input) {
        if (isdigit(c)) {
            numbers.push_back(c - '0');
        }
    }

    if (isFibonacciSequence(numbers)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}