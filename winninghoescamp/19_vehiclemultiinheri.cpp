#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string brand, model;
    double mileage;

public:
    Vehicle(string b, string m, double mi) : brand(b), model(m), mileage(mi) {}
    virtual void displayDetails() = 0;
};

class Car : public Vehicle {
protected:
    double fuel, distance;

public:
    Car(string b, string m, double mi, double f, double d)
        : Vehicle(b, m, mi), fuel(f), distance(d) {}
    void displayDetails() override {
        double fuelEfficiency = distance / fuel;
        cout << "Vehicle: " << brand << " " << model << "\nMileage: " << mileage
             << "\nFuel Efficiency: " << fuelEfficiency << " miles/gallon" << endl;
    }
};

class ElectricCar : public Vehicle {
    double batteryCapacity, efficiency;

public:
    ElectricCar(string b, string m, double mi, double bc, double eff)
        : Vehicle(b, m, mi), batteryCapacity(bc), efficiency(eff) {}
    void displayDetails() override {
        double range = batteryCapacity * efficiency;
        cout << "Vehicle: " << brand << " " << model << "\nMileage: " << mileage
             << "\nRange: " << range << " miles" << endl;
    }
};

int main() {
    int type;
    string brand, model;
    double mileage, fuel, distance, batteryCapacity, efficiency;
    cin >> type;
    if (type == 1) {
        cin >> brand >> model >> mileage >> fuel >> distance;
        Car c(brand, model, mileage, fuel, distance);
        c.displayDetails();
    } else if (type == 2) {
        cin >> brand >> model >> mileage >> batteryCapacity >> efficiency;
        ElectricCar e(brand, model, mileage, batteryCapacity, efficiency);
        e.displayDetails();
    } else {
        cout << "Invalid vehicle type.\n";
    }
    return 0;
}
