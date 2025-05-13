/*
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

double Per(double a, double b, double c)
{
    return a + b + c;
}

int main()
{
    int n;
    cout << "triangles: ";
    cin >> n;

    vector<pair<double, tuple<double, double, double>>> triangles;

    for (int i = 0; i < n; ++i)
    {
        double a, b, c;
        cout << "sides of triangle " << i + 1 << ": ";
        cin >> a >> b >> c;
        double perimeter = Per(a, b, c);
        triangles.push_back(make_pair(perimeter, make_tuple(a, b, c)));
    }

    sort(triangles.begin(), triangles.end());

    for (const auto &triangle : triangles)
    {
        double perimeter = triangle.first;
        double a, b, c;
        tie(a, b, c) = triangle.second;
        cout << "Sides: (" << a << ", " << b << ", " << c << ") - Perimeter: " << perimeter << endl;
    }

    return 0;
} */



#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>

using namespace std;


double calculateArea(double a, double b, double c) {
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double calculatePerimeter(double a, double b, double c) {
    return a + b + c;
}

int main() {
    int n;
    cout << "Enter the number of triangles: ";
    cin >> n;

    
    vector<tuple<double, double, double, double, double>> triangles;

    for (int i = 0; i < n; ++i) {
        double a, b, c;
        cout << "Enter the sides of triangle " << i + 1 << ": ";
        cin >> a >> b >> c;
        double perimeter = calculatePerimeter(a, b, c);
        double area = calculateArea(a, b, c);
        triangles.push_back(make_tuple(perimeter, area, a, b, c));
    }

    
    sort(triangles.begin(), triangles.end());



    cout << "Triangles sorted by perimeter:" << endl;
    for (const auto& triangle : triangles) {
        double perimeter, area, a, b, c;
        tie(perimeter, area, a, b, c) = triangle;
        cout << "Sides: (" << a << ", " << b << ", " << c << ") - Perimeter: " << perimeter << ", Area: " << area << endl;
    }

    return 0;
}
