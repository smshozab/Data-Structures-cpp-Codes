#include <iostream>
#include <string>

using namespace std;

bool isHeap(int arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;

        if (leftChild < n && arr[i] > arr[leftChild])
            return false;

        if (rightChild < n && arr[i] > arr[rightChild])
            return false;
    }

    return true;
}

string identifyHeapType(int arr[], int n) {
    if (isHeap(arr, n)) {
        if (arr[0] < arr[n - 1])
            return "Max Heap";
        else
            return "Min Heap";
    } else {
        return "Not a Heap";
    }
}

int main() {
    int levelOrder[] = {0, 1, 2, 9, 6, 3, 5, 8, 4};
    int n = sizeof(levelOrder) / sizeof(levelOrder[0]);

    string heapType = identifyHeapType(levelOrder, n);

    cout << "The given tree is " << heapType << endl;

    return 0;
}
