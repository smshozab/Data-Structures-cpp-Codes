#include<iostream>
using namespace std;

int main() {
    int nums[5], target = 0, i, j;
    bool found = false;

    for (i = 0; i < 5; i++) {
        cout << "Enter " << i + 1 << " element: ";
        cin >> nums[i];
    }
    cout << "Enter target: "; 
    cin >> target;

    for (i = 0; i < 5; i++) {
        for (j = i + 1; j < 5; j++) {
            if (target == nums[i] + nums[j]) {
                found = true;
                break;
            }
        }
        if (found)
            break;
    }

    if (found)
        cout << "[" << i << "," << j << "]" << endl;
    else
        cout << "Not found" << endl;

    return 0;
}