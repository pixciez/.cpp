#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> l1 = {1, 3, 5};
    list<int> l2 = {2, 4, 6};
    l1.merge(l2);
    l1.sort();
    for (int x : l1) cout << x << " ";
    return 0;
}



/* #include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> l1, l2;
    int n1, n2, val;

    cout << "Enter the number of elements for list 1: ";
    cin >> n1;
    cout << "Enter " << n1 << " elements for list 1: ";
    for (int i = 0; i < n1; ++i) {
        cin >> val;
        l1.push_back(val);
    }

    cout << "Enter the number of elements for list 2: ";
    cin >> n2;
    cout << "Enter " << n2 << " elements for list 2: ";
    for (int i = 0; i < n2; ++i) {
        cin >> val;
        l2.push_back(val);
    }

    l1.merge(l2);
    l1.sort();

    cout << "Merged and sorted list: ";
    for (int x : l1) cout << x << " ";
    cout << endl;

    return 0;
}
*/