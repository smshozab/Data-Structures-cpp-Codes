//Explanation at the end of the code

#include <iostream>
using namespace std;

void bidirectionalBubbleSort(int arr[], int n) {
    bool swapped=true;
    int start=0;
    int end=n-1;

    while(swapped){
        swapped=false;

        for (int i=start;i<end;i++) {
            if (arr[i]>arr[i+1]) {
                swap(arr[i],arr[i+1]);
                swapped=true;
            }
        }
        --end;

        for (int i=end;i>start;--i) {
            if (arr[i]<arr[i-1]) {
                swap(arr[i],arr[i - 1]);
                swapped = true;
            }
        }
        ++start;
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int *arr=new int[n];
    cout << "Enter " << n << " elements: ";
    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }

    bidirectionalBubbleSort(arr, n);

    cout << "Sorted array: ";
    for (int i=0;i<n;i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete []arr;
    return 0;
}

//Stability:
//Both bidirectional bubble sort and adaptive bubble sort are stable sorting algorithms.

//Adaptation:
//Adaptive bubble sort stops early if data is sorted or nearly sorted. Bidirectional bubble sort moves 
//forward and backward, enhancing efficiency, especially for large or disorderly arrays. Both are 
//adaptive, but bidirectional sort may slightly excel due to its bidirectional nature.

//Inplace:
//Both bidirectional bubble sort and adaptive bubble sort are inpolace