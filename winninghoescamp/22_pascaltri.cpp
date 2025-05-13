#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> triangle;
    for (int i = 0; i < numRows; ++i) {
        vector<int> row(i + 1, 1);
        for (int j = 1; j < i; ++j) {
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
        triangle.push_back(row);
    }
    return triangle;
}

int main() {
    int numRows = 5;
    vector<vector<int>> result = generate(numRows);
    for (auto row : result) {
        for (int num : row) cout << num << " ";
        cout << endl;
    }
    return 0;
}
