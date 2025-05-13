#include <iostream>
#include <vector>
using namespace std;

void operate(const vector<vector<int>>& A, const vector<vector<int>>& B, int op) {
    int m = A.size(), n = A[0].size(), p = B[0].size();
    if (op == 1) { // Matrix Addition
        if (m != B.size() || n != B[0].size()) {
            cout << "Invalid dimensions for operation." << endl;
            return;
        }
        vector<vector<int>> result(m, vector<int>(n));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                result[i][j] = A[i][j] + B[i][j];
        for (const auto& row : result) {
            for (int val : row)
                cout << val << " ";
            cout << endl;
        }
    } else if (op == 2) { // Matrix Multiplication
        if (n != B.size()) {
            cout << "Invalid dimensions for operation." << endl;
            return;
        }
        vector<vector<int>> result(m, vector<int>(p, 0));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < p; ++j)
                for (int k = 0; k < n; ++k)
                    result[i][j] += A[i][k] * B[k][j];
        for (const auto& row : result) {
            for (int val : row)
                cout << val << " ";
            cout << endl;
        }
    } else {
        cout << "Invalid operation type." << endl;
    }
}

int main() {
    vector<vector<int>> A = {{1, 2}, {3, 4}};
    vector<vector<int>> B = {{5, 6}, {7, 8}};
    int op;
    cin >> op;
    operate(A, B, op);
    return 0;
}
