#include<iostream>
using namespace std;

int main(){
    int N, count=0;
    cout << "Enter the size of the array" << endl;
    cin >> N;
    int *arr=new int[N];

    for (int i=0;i<N;i++){
        cout << "Enter the value " << i+1 << endl;
        cin >> arr[i];
    }

    for (int i=0;i<N;i++){
        for (int j=i+1;j<N;j++){
            if(arr[i]>arr[j]){
                cout << "(" << arr[i] << "," << arr[j] << ") is an inversion because " << arr[i] << " > " << arr[j] << endl;
                count++;
            }
        }
    }
    cout << "So, there are a total of " << count << " inversions in the given array." << endl;

    delete []arr;
    return 0;
}