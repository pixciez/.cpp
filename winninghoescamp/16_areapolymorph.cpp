#include <iostream>
#include <iomanip>
using namespace std;

class Shape {
public:
    virtual double area() const = 0; // Pure virtual function
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return 3.14159 * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double length, breadth;

public:
    Rectangle(double l, double b) : length(l), breadth(b) {}
    double area() const override {
        return length * breadth;
    }
};

class Triangle : public Shape {
private:
    double base, height;

public:
    Triangle(double b, double h) : base(b), height(h) {}
    double area() const override {
        return 0.5 * base * height;
    }
};

int main() {
    double radius, length, breadth, base, height;
    cin >> radius >> length >> breadth >> base >> height;

    Circle circle(radius);
    Rectangle rectangle(length, breadth);
    Triangle triangle(base, height);

    cout << fixed << setprecision(2);
    cout << "Circle Area: " << circle.area() << endl;
    cout << "Rectangle Area: " << rectangle.area() << endl;
    cout << "Triangle Area: " << triangle.area() << endl;

    return 0;
}
