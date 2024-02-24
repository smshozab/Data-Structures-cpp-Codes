#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter n" << endl;
    cin >> n;
    int **arr = new int*[n];
    float *avg = new float[n];
    int *size = new int[n];
    // int size[10];
    // float avg[n];
    
    for (int i=0;i<n;i++){
        cout<<"Input row "<<i+1<< " size: ";
        cin>>size[i];
        arr[i] =new int[size[i]];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<size[i];j++){
            cout<<"Enter row " <<i+1<<" elements: ";
            cin>>arr[i][j];
    }
    }

    for (int i=0;i<n;i++){
        avg[i]=0;
        for (int j=0;j<size[i];j++){
            avg[i]+=arr[i][j];
        }
        avg[i]=avg[i]/size[i];
    }
    for(int i=0;i<n;i++){
        cout << avg[i] << " ";
    }

    for (int i = 0; i < n; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
    delete[] avg;

    return 0;
}