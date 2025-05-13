#include <iostream>
#include <cmath>
using namespace std;

class Complex {
    double real, imag;

public:
    Complex(double r, double i) : real(r), imag(i) {}

    Complex add(const Complex& c) {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex multiply(const Complex& c) {
        return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
    }

    double magnitude() {
        return sqrt(real * real + imag * imag);
    }

    void display() {
        cout << real << (imag < 0 ? " - " : " + ") << abs(imag) << "i";
    }
};

int main() {
    int type;
    double r1, i1, r2, i2;
    cin >> type;
    if (type == 1) {
        cin >> r1 >> i1 >> r2 >> i2;
        Complex c1(r1, i1), c2(r2, i2);
        Complex result = c1.add(c2);
        result.display();
    } else if (type == 2) {
        cin >> r1 >> i1 >> r2 >> i2;
        Complex c1(r1, i1), c2(r2, i2);
        Complex result = c1.multiply(c2);
        result.display();
    } else if (type == 3) {
        cin >> r1 >> i1;
        Complex c(r1, i1);
        cout << "Magnitude = " << c.magnitude();
    } else {
        cout << "Invalid operation type.\n";
    }
    return 0;
}
