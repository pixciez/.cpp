#include <iostream>
#include <vector>
using namespace std;


bool canAchieveMinPower(int minPower, vector<int>& stations, int r, int k) {
    int n = stations.size();
    vector<long long> power(n, 0), needed(n, 0);
    
    for (int i = 0; i < n; i++) {
        power[i] = stations[i];
        for (int j = max(0, i - r); j <= min(n - 1, i + r); j++) {
            power[j] += stations[i];
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (power[i] < minPower) {
            needed[i] = minPower - power[i];
            k -= needed[i];
            if (k < 0) return false;
        }
    }
    
    return true;
}

int maxMinPower(vector<int>& stations, int r, int k) {
    int left = 0, right = 1e9;
    while (left < right) {
        int mid = (left + right + 1) / 2;
        if (canAchieveMinPower(mid, stations, r, k)) left = mid;
        else right = mid - 1;
    }
    return left;
}

int main() {
    int n, r, k;
    cout << "Enter number of cities: ";
    cin >> n;
    vector<int> stations(n);
    cout << "Enter the number of power stations in each city: ";
    for (int i = 0; i < n; i++) cin >> stations[i];
    
    cout << "Enter the range of each station: ";
    cin >> r;
    cout << "Enter the number of additional power stations: ";
    cin >> k;
    
    cout << "Maximum possible minimum power: " << maxMinPower(stations, r, k) << endl;
    return 0;
}
