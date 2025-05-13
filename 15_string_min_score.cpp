#include <iostream>
#include <string>
#include <vector>
using namespace std;


int minScore(string s, string t) {
    int n = s.size(), m = t.size();
    vector<int> leftMatch(m + 1, -1), rightMatch(m + 1, n);

    for (int i = 0, j = 0; i < n && j < m; i++) {
        if (s[i] == t[j]) leftMatch[++j] = i;
    }

    for (int i = n - 1, j = m - 1; i >= 0 && j >= 0; i--) {
        if (s[i] == t[j]) rightMatch[j--] = i;
    }

    int minScore = m;
    for (int i = 0; i <= m; i++) {
        minScore = min(minScore, rightMatch[i] - leftMatch[i] - 1);
    }

    return minScore;
}

int main() {
    string s, t;
    cout << "Enter string s: ";
    cin >> s;
    cout << "Enter string t: ";
    cin >> t;
    
    cout << "Minimum score to make t a subsequence of s: " << minScore(s, t) << endl;
    return 0;
}
