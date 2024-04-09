#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to swap two elements in an array
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Function to partition the array using the first element as pivot
int partitionFirst(vector<int>& arr, int low, int high, int& comparisons) {
    int pivot = arr[low];
    int i = low + 1;
    for (int j = low + 1; j <= high; j++) {
        comparisons++;
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[low], arr[i - 1]);
    return i - 1;
}

// Function to partition the array using a random element as pivot
int partitionRandom(vector<int>& arr, int low, int high, int& comparisons) {
    int randomIndex = low + rand() % (high - low + 1);
    swap(arr[randomIndex], arr[low]);
    return partitionFirst(arr, low, high, comparisons);
}

// Function to partition the array using the middle element as pivot
int partitionMiddle(vector<int>& arr, int low, int high, int& comparisons) {
    int mid = low + (high - low) / 2;
    swap(arr[mid], arr[low]);
    return partitionFirst(arr, low, high, comparisons);
}

// Function to perform quicksort with different pivot selection techniques
void quickSort(vector<int>& arr, int low, int high, string pivotType, int& comparisons) {
    if (low < high) {
        int pivotIndex;
        if (pivotType == "first") {
            pivotIndex = partitionFirst(arr, low, high, comparisons);
        } else if (pivotType == "random") {
            pivotIndex = partitionRandom(arr, low, high, comparisons);
        } else if (pivotType == "middle") {
            pivotIndex = partitionMiddle(arr, low, high, comparisons);
        }
        quickSort(arr, low, pivotIndex - 1, pivotType, comparisons);
        quickSort(arr, pivotIndex + 1, high, pivotType, comparisons);
    }
}

int main() {
    vector<int> arr = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5 };
    int comparisonsFirst = 0, comparisonsRandom = 0, comparisonsMiddle = 0;

    vector<int> arrFirst = arr;
    quickSort(arrFirst, 0, arrFirst.size() - 1, "first", comparisonsFirst);
    cout << "Comparisons using first element as pivot: " << comparisonsFirst << endl;

    srand(time(0)); // Seed for random number generation
    vector<int> arrRandom = arr;
    quickSort(arrRandom, 0, arrRandom.size() - 1, "random", comparisonsRandom);
    cout << "Comparisons using random element as pivot: " << comparisonsRandom << endl;

    vector<int> arrMiddle = arr;
    quickSort(arrMiddle, 0, arrMiddle.size() - 1, "middle", comparisonsMiddle);
    cout << "Comparisons using middle element as pivot: " << comparisonsMiddle << endl;

    return 0;
}


//As seen, the comparions by taking first element as a pivot were less than both by taking middle or by taking random element as a pivot. However, we cannot make final decision on the basis of this. Generally, random pivot selection tends to perform well on average, while selecting the first or middle element can lead to worst-case scenarios if the array is already sorted or nearly sorted.