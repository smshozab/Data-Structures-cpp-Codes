#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

void calculateFactorials(int index, int size, int arr[]) {
    if (index >= size) {
        return;
    }

    arr[index] = factorial(arr[index]);

    cout << "Factorial of element at index " << index << " is: " << arr[index] << endl;

    // Recursive call
    calculateFactorials(index + 1, size, arr);
}

int main() {
    int s;
    cout << "Enter the size of the array: " << endl;
    cin >> s;

	int array[100];
	
    // Taking input
    for (int i = 0; i < s; i++) {
        cout << "Enter the value at index " << i << " in the array: ";
        cin >> array[i];

        if (array[i] < 0) {
            cout << "ERROR! Enter again" << endl;
            cin >> array[i];
        }
    }

    calculateFactorials(0, s, array);

    return 0;
}