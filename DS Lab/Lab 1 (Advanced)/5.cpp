#include<iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "Input rows" << endl;
    cin >> rows;
    cout << "Input cols" << endl;
    cin >> cols;
    int **arr=new int* [rows];

    for (int i=0;i<rows;++i) {
        arr[i]=new int[cols];
    }

    for(int i=0;i<rows;i++){
        for (int j=0;j<cols;j++){
            cout << "Input the element at  " << i+1 << " row and " << j+1 << " column of the array" << endl;
            cin >> arr[i][j];
        }
    }
    cout << "Array before transpose:" << endl;
    for(int i=0;i<rows;i++){
        for (int j=0;j<cols;j++){
            cout << "[" << arr[i][j] << "]";
        }
        cout << endl;
    }

    for(int i=0;i<rows;i++){
        for (int j=i+1;j<cols;j++){
            swap(arr[i][j],arr[j][i]);
        }
    }

    // for(int i=0;i<rows;i++){
    //     for (int j=0;j<cols;j++){
    //         cout << arr[i][j];
    //     }
    // }
    cout << "Array after transpose:" << endl;
    for(int i=0;i<rows;i++){
        for (int j=0;j<cols;j++){
            cout << "[" << arr[i][j] << "]";
        }
        cout << endl;
    }
    for (int i = 0; i < rows; ++i) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}