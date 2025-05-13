#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> vecA = {1, 2, 3, 4, 5};
    vector<int> vecB = move(vecA); // Move vecA to vecB (vecA becomes empty)

    cout << "vecA (after move): ";
    for (int val : vecA) cout << val << " ";
    cout << endl;

    cout << "vecB (moved from vecA): ";
    for (int val : vecB) cout << val << " ";
    cout << endl;

    vector<int> boxX = {6, 7, 8, 9, 10};
    vector<int> boxY = boxX; // Copy contents from boxX to boxY

    cout << "boxX (original): ";
    for (int val : boxX) cout << val << " ";
    cout << endl;

    cout << "boxY (copied from boxX): ";
    for (int val : boxY) cout << val << " ";
    cout << endl;

    return 0;
}
