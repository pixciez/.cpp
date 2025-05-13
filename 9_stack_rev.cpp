#include <iostream>
#include <list>
#include <stack>

using namespace std;

int main() {
    list<int> lst;
    int n;

    cout << "Enter numbers to add to the list (non-integer to stop): ";

    // Read numbers from input and add them to the list
    while (cin >> n) {
        lst.push_back(n);
    }

    // Use a stack to print the list in reverse order
    stack<int> s;
    for (int x : lst) {
        s.push(x);
    }

    cout << "Reversed list: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}
