/*
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum = 0;
    
        for (int i = 0; i < n; ++i) {
        
            sum += mat[i][i];
            sum += mat[i][n - 1 - i];
        }
        
        if (n % 2 != 0) {
            sum -= mat[n / 2][n / 2];
        }
        
        return sum;
    }
};

--------------------------------------------------------------------------------------

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        
        int diagonalSum {};

        for(int i = 0; i < mat.size(); ++i){
            for(int j = 0; j < mat[i].size(); ++j){
                if(i == j || i < j && (i + j) ==  mat.size() - 1 || i > j && (i + j) ==  mat.size() - 1){
                    diagonalSum += mat[i][j];
                } 
            }
        }

        return diagonalSum;
    }
};
*/




// O(n)
// single loop
#include <vector>
#include <iostream>
using namespace std;

int DS(const vector<vector<int>>& mat) {
    int n = mat.size();
    int lsum = 0;
    int rsum = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                lsum += mat[i][j]; 
            }
            if (i + j == n - 1) {
                rsum += mat[i][j]; 
            }
        }
    }

    int sum = lsum + rsum;

    if (n % 2 != 0) {
        sum -= mat[n / 2][n / 2]; 
    }

    return sum;
}

void DD(const vector<vector<int>>& mat) {
    int n = mat.size();
    int lsum = 0;
    int rsum = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                lsum += mat[i][j]; 
            }
            if (i + j == n - 1) {
                rsum += mat[i][j]; 
            }
        }
    }

    int diff = lsum - rsum;

    if (diff == 0) {
        cout << "Difference is 0" << endl;
    } else {
        cout << "Difference is " << diff << endl;
    }
}

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    cout << "Sum of diagonals: " << DS(mat) << endl;
    DD(mat);
    return 0;
}




