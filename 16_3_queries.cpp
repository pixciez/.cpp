#include <iostream>
#include <vector>
using namespace std;


vector<int> processQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
    vector<int> result;
    for (auto& query : queries) {
        if (query[0] == 1) {
            for (int i = query[1]; i <= query[2]; i++) {
                nums1[i] ^= 1;
            }
        } else if (query[0] == 2) {
            for (int i = 0; i < nums2.size(); i++) {
                nums2[i] += nums1[i] * query[1];
            }
        } else if (query[0] == 3) {
            int sum = 0;
            for (int num : nums2) {
                sum += num;
            }
            result.push_back(sum);
        }
    }
    return result;
}

int main() {
    int n, q;
    cout << "Enter the size of arrays nums1 and nums2: ";
    cin >> n;
    
    vector<int> nums1(n), nums2(n);
    cout << "Enter elements of nums1: ";
    for (int i = 0; i < n; i++) cin >> nums1[i];
    
    cout << "Enter elements of nums2: ";
    for (int i = 0; i < n; i++) cin >> nums2[i];
    
    cout << "Enter the number of queries: ";
    cin >> q;
    
    vector<vector<int>> queries(q, vector<int>(3));
    cout << "Enter the queries (format: [type, l, r/p]):\n";
    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
    }
    
    vector<int> result = processQueries(nums1, nums2, queries);
    cout << "Results of type-3 queries: ";
    for (int res : result) cout << res << " ";
    cout << endl;
    return 0;
}
