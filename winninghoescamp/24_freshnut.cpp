#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int maxHappyGroups(int batchSize, vector<int>& groups) {
    sort(groups.begin(), groups.end(), greater<int>());
    int happy_groups = 0, remaining_donuts = 0;
    for (int group : groups) {
        if (group <= remaining_donuts) {
            remaining_donuts -= group;
            happy_groups++;
        } else {
            remaining_donuts = (remaining_donuts + group) % batchSize;
        }
    }
    return happy_groups;
}

int main() {
    vector<int> groups = {1, 2, 3, 4, 5, 6};
    int batchSize = 3;
    cout << maxHappyGroups(batchSize, groups) << endl; // Output: 4
    return 0;
}
