#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
    int N,K,sum=0,count=0;
    cout << "Enter N" << endl;
    cin >> N;
    cout << "Enter K" << endl;
    cin >> K;

    int arr[100];

    for (int i=0;i<N;i++) {
        cout << "Input the value " << i+1 << " of the array" << endl;
        cin >> arr[i];
    }

    for (int j = 0; j < N - 1; j++) {
        bool swapped = false;
        for (int k=0;k<N-j-1;k++) {
            if (arr[k]>arr[k+1]) {
                swap(arr[k], arr[k+1]);
                swapped=true;
            }
        }
        if (!swapped)
            break;
    }

    for (int i=0;i<N;i++) {
        if (sum+arr[i]<=K) {
            sum+=arr[i];
            count++;
        } else {
            break; 
        }
    }
    cout << "The maximum number of toys you can buy with " << K << " amount is:" << count;
}
