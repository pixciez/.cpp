#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
int largestDigit(int n) {
    int maxDigit = 0;
    while (n > 0) {
        maxDigit = max(maxDigit, n % 10);
        n /= 10;
    }
    return maxDigit;
}

int main() {
    int n;
    cin >> n;
    cout << largestDigit(n) << endl;
    return 0;
}
*/



bool isPalindrome(int n) {
    string num = to_string(n);
    string revNum = num;
    reverse(revNum.begin(), revNum.end());
    return num == revNum;
}

int main() {
    int n;
    cin >> n;
    cout << (isPalindrome(n) ? "Palindrome" : "Not Palindrome") << endl;
    return 0;
}
