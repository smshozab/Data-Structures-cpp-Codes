#include<iostream>
using namespace std;

int main() {
    int rows, cols, key;
    cout << "Input rows" << endl;
    cin >> rows;
    cout << "Input cols" << endl;
    cin >> cols;
    cout << "Input what you want to search" << endl;
    cin >> key;
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

    for(int i=0;i<rows;i++){
        for (int j=0;j<cols;j++){
            if(arr[i][j]==key){
                cout << i << "," << j;
            }
        }
    } 
}