#include <iostream>
#include <string>
using namespace std;

void reverseString(string &str, int sub) {
    if (sub >= str.length() - 1 - sub) {
        return;
    }

    char temp = str[sub];
    str[sub] = str[str.length() - 1 - sub];
    str[str.length() - 1 - sub] = temp;

    reverseString(str, sub + 1);
}

int main() {
    string str;
    // Taking input
    cout << "Enter the string:" << endl;
    getline(cin, str);
    
	reverseString(str, 0);
	cout << "Reversed String: " << str << endl;
    return 0;
}