#include <iostream>
using namespace std;

class Shape {
public:
    double area(double r) { return 3.14159 * r * r; }
    int area(int l, int b) { return l * b; }
    double area(double b, double h) { return 0.5 * b * h; }
};

int main() {
    Shape s;
    cout << s.area(5.0) << endl;        
    cout << s.area(4, 6) << endl;     
    cout << s.area(3.0, 7.0) << endl;   
    return 0;
}