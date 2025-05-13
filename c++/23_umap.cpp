#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void freq(vector<int> &arr){
    unordered_map<int, int> m;
    for (int i : arr)
        m[i]++;
    for (auto p : m)
        cout << p.first << ": " << p.second << endl;
}

int main(){
  /*
    int n, x;
    vector<int> arr;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x;
        arr.push_back(x);
    }
  */
    vector<int> arr = {1, 2, 3, 4, 1, 2, 1, 3, 8, 4, 5,};
    freq(arr);
    return 0;
}











