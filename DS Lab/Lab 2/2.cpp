#include<iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "Input rows" << endl;
    cin >> rows;
    cout << "Input cols" << endl;
    cin >> cols;
    int **arr=new int* [rows];
    int *avg= new int [rows];
    // int **avg=new int* [rows];

    for (int i=0;i<rows;++i) {
        arr[i]=new int[cols];
        // avg[i]=new int[cols];
    }

    for(int i=0;i<rows;i++){
        for (int j=0;j<cols;j++){
            cout << "Input the element at  " << i+1 << " row and " << j+1 << " column of the array" << endl;
            cin >> arr[i][j];
        }
    }

    for (int i=0;i<rows;i++){
        avg[i]=0;
        for (int j=0;j<cols;j++){
            avg[i]+=arr[i][j];
        }
        avg[i]=avg[i]/cols;
    }
    for(int i=0;i<rows;i++){
        cout << avg[i] << endl;
    }

    for (int i = 0; i < rows; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
    delete[] avg;

    return 0;
}