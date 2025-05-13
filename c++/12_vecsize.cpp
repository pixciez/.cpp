#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> numbers;
    int num;
    int sum = 0;

    cout << "Enter integers (enter -1 to stop):" << endl;
    while (cin >> num && num != -1)
    {
        numbers.push_back(num);
        sum += num;
    }

    cout << "Sum of integers: " << sum << endl;
    cout << "Count of integers taken for sum: " << numbers.size() << endl;

    return 0;
}
