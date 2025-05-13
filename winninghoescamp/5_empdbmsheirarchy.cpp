#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    int id, salary;
public:
    Employee(string n, int i, int s) : name(n), id(i), salary(s) {}
    virtual void calculateEarnings() = 0;
    virtual ~Employee() {}
};

class Manager : public Employee {
    int rating;
public:
    Manager(string n, int i, int s, int r) : Employee(n, i, s), rating(r) {}
    void calculateEarnings() override {
        int bonus = salary * rating * 0.1;
        cout << "Employee: " << name << " (ID: " << id << ")\nRole: Manager\nBase Salary: " 
             << salary << "\nBonus: " << bonus << "\nTotal Earnings: " << salary + bonus << endl;
    }
};

class Developer : public Employee {
    int hours;
public:
    Developer(string n, int i, int s, int h) : Employee(n, i, s), hours(h) {}
    void calculateEarnings() override {
        int overtime = hours * 500;
        cout << "Employee: " << name << " (ID: " << id << ")\nRole: Developer\nBase Salary: " 
             << salary << "\nOvertime Compensation: " << overtime << "\nTotal Earnings: " 
             << salary + overtime << endl;
    }
};

int main() {
    int type;
    cin >> type;
    if (type == 1) {
        string n;
        int i, s, r;
        cin >> n >> i >> s >> r;
        Manager m(n, i, s, r);
        m.calculateEarnings();
    } else if (type == 2) {
        string n;
        int i, s, h;
        cin >> n >> i >> s >> h;
        Developer d(n, i, s, h);
        d.calculateEarnings();
    } else {
        cout << "Invalid employee type." << endl;
    }
    return 0;
}
