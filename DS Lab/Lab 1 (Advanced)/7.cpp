#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int>& height) {
    int n = height.size();
    int maxWater = 0;
    int left = 0, right = n - 1;

    while (left < right) {
        int h = min(height[left], height[right]);
        int w = right - left;
        int area = h * w;
        maxWater = max(maxWater, area);

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return maxWater;
}

int main() {
    int n;
    cout << "Enter the number of vertical lines: ";
    cin >> n;

    vector<int> height(n);
    cout << "Enter the heights of the vertical lines:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> height[i];
    }

    int max_water = maxArea(height);

    cout << "Maximum amount of water that can be trapped: " << max_water << endl;

    return 0;
}
