#include <iostream>
#include <vector>
using namespace std;


long long countFixedBoundSubarrays(vector<int>& nums, int minK, int maxK) {
    long long count = 0;
    int left = -1, minPos = -1, maxPos = -1;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] < minK || nums[i] > maxK) left = i;
        if (nums[i] == minK) minPos = i;
        if (nums[i] == maxK) maxPos = i;
        count += max(0, min(minPos, maxPos) - left);
    }
    return count;
}

int main() {
    int n, minK, maxK;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) cin >> nums[i];
    
    cout << "Enter minK and maxK: ";
    cin >> minK >> maxK;
    
    cout << "Number of fixed-bound subarrays: " << countFixedBoundSubarrays(nums, minK, maxK) << endl;
    return 0;
}
