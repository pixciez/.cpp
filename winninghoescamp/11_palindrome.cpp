#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
 
/* bool isPalindrome(int n) {
    int original = n, reversed = 0;
    while (n > 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return original == reversed;
}

int main() {
    int n;
    cin >> n;
    cout << (isPalindrome(n) ? "Palindrome" : "Not Palindrome") << endl;
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
    cout << "inp :\n";
    cin >> n;
    cout << (isPalindrome(n) ? "Palindrome" : "Not Palindrome") << endl;
    return 0;
}
