#include <iostream>
#include <algorithm>
using namespace std;

void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

void deleteFromMaxHeap(int arr[], int& n, int val) {
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == val) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Value not found in heap." << endl;
        return;
    }

    arr[index] = arr[n - 1];
    n--;
    maxHeapify(arr, n, index);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {35, 33, 42, 10, 14, 19, 27, 44, 26, 31};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Create Max Heap and Delete 42
    buildMaxHeap(arr, n);
    deleteFromMaxHeap(arr, n, 42);

    cout << "Max Heap after deleting 42: ";
    printArray(arr, n);

    // Create Min Heap and Delete 35
    make_heap(arr, arr + n, greater<int>());
    pop_heap(arr, arr + n);
    n--;

    cout << "Min Heap after deleting 35: ";
    printArray(arr, n);

    sort_heap(arr, arr + n, greater<int>());
    
    cout << "Sorted Max Heap: ";
    printArray(arr, n);

    return 0;
}
