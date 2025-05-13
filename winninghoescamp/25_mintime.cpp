#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <numeric>  // Include for accumulate
using namespace std;

bool assignJobs(vector<int>& jobs, int i, vector<int>& workers, int max_time);

bool canFinishJobs(vector<int>& jobs, int k, int max_time) {
    vector<int> workers(k, 0);
    return assignJobs(jobs, 0, workers, max_time);
}

bool assignJobs(vector<int>& jobs, int i, vector<int>& workers, int max_time) {
    if (i == jobs.size()) return true;
    for (int j = 0; j < workers.size(); ++j) {
        if (workers[j] + jobs[i] <= max_time) {
            workers[j] += jobs[i];
            if (assignJobs(jobs, i + 1, workers, max_time)) return true;
            workers[j] -= jobs[i];
        }
    }
    return false;
}

int minimumTimeRequired(vector<int>& jobs, int k) {
    int left = *max_element(jobs.begin(), jobs.end()), right = accumulate(jobs.begin(), jobs.end(), 0);
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (canFinishJobs(jobs, k, mid)) right = mid;
        else left = mid + 1;
    }
    return left;
}

int main() {
    vector<int> jobs = {3, 2, 3};
    int k = 3;
    cout << minimumTimeRequired(jobs, k) << endl; 
    return 0;
}
