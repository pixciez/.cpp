/*
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    vector<int> arr = {1, 2, 2, 3, 4, 4, 4, 5};
    unordered_map<int, int> frequencyMap;
    for (int num : arr) {
        auto result = frequencyMap.emplace(num, 0);
        result.first->second++;
    }
    cout << "Element Frequencies:\n";
    for (const auto &pair : frequencyMap) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}
*/


#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "no. of elements in array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    unordered_map<int, int> frequencyMap;
    for (int num : arr) {
        frequencyMap[num]++;
    }

    cout << "Element Frequencies:\n";
    for (const auto &pair : frequencyMap) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}
