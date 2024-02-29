#include <iostream>
using namespace std;

void adaptive_selection_sort(int arr[], int n) {
    for (int i=0;i<n;i++) {
        int min_idx=i;
        for (int j=i+1;j<n;j++) {
            if (arr[j]<arr[min_idx]) {
                min_idx=j;
            }
        }
        if (min_idx != i) {
            swap(arr[i],arr[min_idx]);
        }
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
    adaptive_selection_sort(arr, n);
    cout << "Sorted array: ";
    for (int i=0;i<n;i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}