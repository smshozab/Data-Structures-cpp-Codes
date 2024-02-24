#include<iostream>
#include<algorithm>
using namespace std;

class Array2D {
private:
    int rows;
    int cols;
    int **arr;

public:
    Array2D(int r, int c) : rows(r), cols(c) {
        arr = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            arr[i] = new int[cols];
        }
    }

    ~Array2D() {
        for (int i = 0; i < rows; ++i) {
            delete[] arr[i];
        }
        delete[] arr;
    }

    int& operator()(int i, int j) {
        if (i < 0 || i >= rows || j < 0 || j >= cols) {
            throw out_of_range("Boundary Error");
        }
        return arr[i][j];
    }

    void transpose() {
        for (int i = 0; i < rows; ++i) {
            for (int j = i + 1; j < cols; ++j) {
                swap(arr[i][j], arr[j][i]);
            }
        }
    }

    void print() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << "[" << arr[i][j] << "]";
            }
            cout << endl;
        }
    }
};

int main() {
    int rows, cols;
    cout << "Input rows" << endl;
    cin >> rows;
    cout << "Input cols" << endl;
    cin >> cols;

    Array2D arr2D(rows, cols);

    for(int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Input the element at " << i + 1 << " row and " << j + 1 << " column of the array" << endl;
            cin >> arr2D(i, j);
        }
    }

    cout << "Original Array" << endl;
    arr2D.print();

    arr2D.transpose();

    cout << "Transposed array" << endl;
    arr2D.print();

    return 0;
}