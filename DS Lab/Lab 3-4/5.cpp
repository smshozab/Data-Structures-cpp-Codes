#include <iostream>
#include <algorithm>
using namespace std;

string frequencySort(string s) {
    int freq[256]={0};
    for (int i=0;i<s.size();++i) {
        freq[s[i]]++;
    }
    
    sort(s.begin(), s.end(), [&](char a, char b) {
        return freq[a] > freq[b] || (freq[a] == freq[b] && a < b);
    });
    return s;
}

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;
    string sortedString = frequencySort(s);
    cout << "Sorted string: " << sortedString << endl;    
    return 0;
}