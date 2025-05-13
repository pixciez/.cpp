#include <iostream>
#include <vector>
using namespace std;

int trap(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int leftMax = 0, rightMax = 0, water = 0;
    
    while (left <= right) {
        if (height[left] < height[right]) {
            if (height[left] >= leftMax) leftMax = height[left];
            else water += leftMax - height[left];
            left++;
        } else {
            if (height[right] >= rightMax) rightMax = height[right];
            else water += rightMax - height[right];
            right--;
        }
    }
    
    return water;
}

int main() {
    int n;
    cout << "Enter number of bars: ";
    cin >> n;
    vector<int> height(n);
    cout << "Enter heights of the bars: ";
    for (int i = 0; i < n; i++) cin >> height[i];
    
    cout << "Maximum water trapped: " << trap(height) << endl;
    return 0;
}
