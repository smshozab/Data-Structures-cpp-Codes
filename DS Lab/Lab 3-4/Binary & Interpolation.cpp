#include <iostream>
using namespace std;

int interpolationSearch(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;
 
    while (low <= high && target >= arr[low] && target <= arr[high]){
        int pos = low + (((target - arr[low]) * (high - low)) / (arr[high] - arr[low]));
 
        if( arr[pos] == target){
            return pos;
        }
 
        if(arr[pos] > target){
            high = pos - 1;
        }
        else{
            low = pos + 1;
        }
    }
    return -1;
}


int binarySearch(int arr[], int low, int high, int target) {
    while (low <= high) {
        int m = low + (high - low) / 2;
 
        if (arr[m] == target)
            return m;
        if (arr[m] < target)
            low = m + 1;
        else
            high = m - 1;
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 4;

    int indexInterpolation = interpolationSearch(arr, n, target);
    int indexBinary = binarySearch(arr, 0, n - 1, target);

    if (indexInterpolation != -1)
        cout << "Element found using Interpolation Search at index " << indexInterpolation << endl;
    else
        cout << "Element not found using Interpolation Search" << endl;

    if (indexBinary != -1)
        cout << "Element found using Binary Search at index " << indexBinary << endl;
    else
        cout << "Element not found using Binary Search" << endl;

    return 0;
}
