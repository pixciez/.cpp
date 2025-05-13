#include <iostream>
#include <string>
using namespace std;

// Abstraction: Base class with pure virtual functions
class Vehicle {
protected:
    string brand; // Encapsulation: private data with controlled access through protected

public:
    Vehicle(const string& brandName) : brand(brandName) {}

    virtual void displayDetails() const = 0; // Pure virtual function (abstraction)

    virtual ~Vehicle() {}
};

// Inheritance: Derived class from Vehicle
class Car : public Vehicle {
private:
    int numDoors; // Encapsulation: private data specific to Car

public:
    Car(const string& brandName, int doors) : Vehicle(brandName), numDoors(doors) {}

    // Polymorphism: Overriding the base class function
    void displayDetails() const override {
        cout << "Brand: " << brand << ", Number of Doors: " << numDoors << endl;
    }
};

// Another Derived class from Vehicle
class Bike : public Vehicle {
private:
    bool hasCarrier; // Encapsulation: private data specific to Bike

public:
    Bike(const string& brandName, bool carrier) : Vehicle(brandName), hasCarrier(carrier) {}

    // Polymorphism: Overriding the base class function
    void displayDetails() const override {
        cout << "Brand: " << brand << ", Has Carrier: " << (hasCarrier ? "Yes" : "No") << endl;
    }
};

int main() {
    Vehicle* v1 = new Car("Toyota", 4); // Using inheritance and abstraction
    Vehicle* v2 = new Bike("Yamaha", true);

    // Polymorphism: Same function call behaves differently for different objects
    v1->displayDetails();
    v2->displayDetails();

    delete v1;
    delete v2;

    return 0;
}
