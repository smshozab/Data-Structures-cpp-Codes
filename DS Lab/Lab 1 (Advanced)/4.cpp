#include<iostream>
using namespace std;

int main() {
    int arr[5];
    int *ptr = arr;

    for (int i = 0; i < 5; i++) {
        cout << "Enter " << i + 1 << " element: ";
        cin >> *(ptr + i);
    }

    for (int i = 0; i < 4; i++) {
        int minIndex = i;
        for (int j = i + 1; j < 5; j++) {
            if (*(ptr + j) < *(ptr + minIndex)) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(*(ptr + i), *(ptr + minIndex));
        }
    }
    cout << "Sorted Array:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << *(ptr + i) << " ";
    }
    cout << endl;

    return 0;
}