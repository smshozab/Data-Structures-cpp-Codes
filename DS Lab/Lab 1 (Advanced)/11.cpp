#include<iostream>
using namespace std;

int main() {
    int n,d;
    cout << "Enter n" << endl;
    cin >> n;
    cout << "Enter d" << endl;
    cin >> d;
    int *arr = new int[n];

    for (int i=0;i<n;i++) {
        cout << "Enter " << i + 1 << " element: ";
        cin >> arr[i];
    }

    for (int i=0;i<n;i++){
        // if (arr[i]+d<=n){
        arr[i]=arr[i]+d;
        if (arr[i]>n){
            arr[i]=arr[i]-n;
        }
        // }
        // else if(arr[i]+d>n){
        //     arr[i]
        // }
    }

    for (int i=0;i<n;i++){
        cout << arr[i];
    }
}