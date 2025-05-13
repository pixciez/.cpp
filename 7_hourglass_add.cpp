#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<vector<int>> m = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {1, 2, 3, 7},
        {0, 0, 2, 4}};

    int n = m.size();
    if (n < 3)
    {
        cout << "Matrix too small for an hourglass." << endl;
        return 1;
    }

    int totalSum = 0;
    for (int i = 0; i < n - 2; ++i)
    {
        for (int j = 0; j < n - 2; ++j)
        {
            int sum = m[i][j] + m[i][j + 1] + m[i][j + 2] +
                      m[i + 1][j + 1] +
                      m[i + 2][j] + m[i + 2][j + 1] + m[i + 2][j + 2];

            totalSum += sum;

            cout << "Hourglass at (" << i << ", " << j << "):" << endl;
            cout << m[i][j] << " " << m[i][j + 1] << " " << m[i][j + 2] << endl;
            cout << "  " << m[i + 1][j + 1] << "  " << endl;
            cout << m[i + 2][j] << " " << m[i + 2][j + 1] << " " << m[i + 2][j + 2] << endl;
            cout << "Sum: " << sum << endl
                 << endl;
        }
    }

    return 0;
}
