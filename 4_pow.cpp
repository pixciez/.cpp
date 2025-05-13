#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int b, e;
    cout << "Enter base: ";
    cin >> b;
    cout << "Enter exponent: ";
    cin >> e;
    if (e == -1)
    {
        cout << 1.0 / e;
        if (e % 2 == 1)
    {
        cout << pow(b, e / 2) * pow(b, (e + 1) / 2) << endl;
    }
    else
    {
        cout << pow(pow(b, e / 2), 2) << endl;
    }
    }
   

    return 0;
}
