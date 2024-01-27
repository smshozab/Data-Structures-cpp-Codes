#include <iostream>
#include <iomanip>
using namespace std;

int S(int index, int size, int matrix[]) {
    if (index >= size - 1) {
        return 1;
    }

    if (matrix[index] > matrix[index + 1]) {
        return 0;
    }

    return S(index + 1, size, matrix);
}

int main() {
    int s;
    cout << "Enter the size of the matrix: " << endl;
    cin >> s;

    int matrix[100];
//  int matrix[];

    // Taking input
    for (int i = 0; i < s; i++) {
        cout << "Enter the value at index " << i << " in the matrix: ";
        cin >> matrix[i];
    }

    if (S(0, s, matrix)) {
        cout << "Sorted" << endl;
    } 
	else {
        cout << "Not sorted" << endl;
    }

    return 0;
}
