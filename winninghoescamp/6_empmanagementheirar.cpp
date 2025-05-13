// Problem 1: Hierarchical Inheritance for Employee Management System
#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    int id;
    int salary;

public:
    Employee(string n, int i, int s) : name(n), id(i), salary(s) {}
    virtual void display() const = 0;
    virtual ~Employee() {}
};

class Manager : public Employee {
    int rating;

public:
    Manager(string n, int i, int s, int r) : Employee(n, i, s), rating(r) {}
    void display() const override {
        int bonus = (salary * 10 / 100) * rating;
        cout << "Employee: " << name << " (ID: " << id << ")\n";
        cout << "Role: Manager\n";
        cout << "Base Salary: " << salary << "\n";
        cout << "Bonus: " << bonus << "\n";
        cout << "Total Earnings: " << salary + bonus << "\n";
    }
};

class Developer : public Employee {
    int extraHours;

public:
    Developer(string n, int i, int s, int h) : Employee(n, i, s), extraHours(h) {}
    void display() const override {
        int overtime = extraHours * 500;
        cout << "Employee: " << name << " (ID: " << id << ")\n";
        cout << "Role: Developer\n";
        cout << "Base Salary: " << salary << "\n";
        cout << "Overtime Compensation: " << overtime << "\n";
        cout << "Total Earnings: " << salary + overtime << "\n";
    }
};

int main() {
    int type;
    cout << "Enter Employee Type (1 for Manager, 2 for Developer): ";
    cin >> type;

    if (type == 1) {
        string name;
        int id, salary, rating;
        cout << "Enter Name, ID, Salary, and Rating: ";
        cin >> name >> id >> salary >> rating;
        if (rating < 1 || rating > 5 || salary < 10000 || salary > 1000000) {
            cout << "Invalid input.\n";
            return 0;
        }
        Manager m(name, id, salary, rating);
        m.display();
    } else if (type == 2) {
        string name;
        int id, salary, hours;
        cout << "Enter Name, ID, Salary, and Extra Hours Worked: ";
        cin >> name >> id >> salary >> hours;
        if (hours < 0 || hours > 100 || salary < 10000 || salary > 1000000) {
            cout << "Invalid input.\n";
            return 0;
        }
        Developer d(name, id, salary, hours);
        d.display();
    } else {
        cout << "Invalid employee type.\n";
    }
    return 0;
}
