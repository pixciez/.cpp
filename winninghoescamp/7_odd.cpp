#include <iostream>
using namespace std;

void printOddAndSum(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i += 2) {
        cout << i << " ";
        sum += i;
    }
    cout << endl << sum << endl;
}

int main() {
    int n;
    cin >> n;
    printOddAndSum(n);
    return 0;
}
