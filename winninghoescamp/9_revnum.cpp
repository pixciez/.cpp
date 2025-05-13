#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

/* int reverseNumber(int n) {
    int reversed = 0;
    while (n > 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return reversed;
}

int main() {
    int n;
    cin >> n;
    cout << reverseNumber(n) << endl;
    return 0;
} */


string reverseNumber(int n) {
    string num = to_string(n);
    reverse(num.begin(), num.end());
    return num;
}

int main() {
    int n;
    cin >> n;
    cout << reverseNumber(n) << endl;
    return 0;
}

