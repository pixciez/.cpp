#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n; // Input number of rows and columns

    vector<vector<int>> mat(m, vector<int>(n)); // Declare m x n matrix

    // Input matrix elements
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    vector<int> row(m, 0), col(n, 0); // Arrays to mark rows and columns to be zeroed

    // First pass: mark rows and columns that contain zero
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 0) {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    // Second pass: set entire row and column to zero if marked
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (row[i] || col[j]) {
                mat[i][j] = 0;
            }
        }
    }

    // Output the final matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
