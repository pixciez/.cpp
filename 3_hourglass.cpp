#include <vector>
#include <iostream>
using namespace std;

    void HG(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int count = 0;
    
        for (int i = 0; i < r - 2; ++i) {
            for (int j = 0; j < c - 2; ++j) {
                int currentSum = grid[i][j] + grid[i][j+1] + grid[i][j+2] +
                                 grid[i+1][j+1] +
                                 grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2];
                
                cout << "Hourglass " << count + 1 << ": " << currentSum << endl;
                        count++;
            }
        }
        
        cout << "hourglasses: " << count << endl;
    }

int main() {
    vector<vector<int>> grid = {{6, 2, 1, 3},{4, 2, 1, 5},{9, 2, 8, 7},{4, 1, 2, 9}};
    HG(grid);
    

    return 0;
}
