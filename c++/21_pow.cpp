#include <iostream>
#include <cmath>

using namespace std;

double power(double b, int e)
{
    if (e == 0)
        return 1;

    double pow = power(b, e / 2);

    if (e % 2 == 0)
        pow = pow * pow;
    else
        pow = b * pow * pow;

    return (e == -1) ? 1 / pow : pow;
}

int main()
{
    double b;
    int e;
    cout << "Enter base: ";
    cin >> b;
    cout << "Enter exponent: ";
    cin >> e;
    cout << "Power(" << b << ", " << e << ") = " << power(b, e) << endl;
    return 0;
}





