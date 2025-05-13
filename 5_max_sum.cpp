#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int maxSumAfterOps(vector<int>& arr, int k, vector<int>& ops) {
    int n = arr.size();
    sort(ops.begin(), ops.end(), greater<int>());
    vector<int> modArr = arr;

    for (int i = 0; i < k; i++) {
        int maxDiff = INT_MIN;
        int idx = -1;
        
        for (int j = 0; j < n; j++) {
            int diff = ops[i] - min(0, arr[j]);
            if (diff > maxDiff) {
                maxDiff = diff;
                idx = j;
            }
        }
        
        if (idx != -1) {
            modArr[idx] += ops[i];
        }
    }

    int maxSum = INT_MIN, currSum = 0;
    for (int num : modArr) {
        currSum = max(num, currSum + num);
        maxSum = max(maxSum, currSum);
    }
    
    return maxSum;
}

int main() {
    vector<int> arr = {1, 2, -3, 4, -5};
    int k = 2;
    vector<int> ops = {3, 1};
    cout << maxSumAfterOps(arr, k, ops) << endl;
    return 0;
}
